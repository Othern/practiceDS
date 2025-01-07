#include <iostream>
#include <pthread.h>
#include <unistd.h> // for sleep()

using namespace std;

// 定義兩個互斥鎖
pthread_mutex_t mutexA;
pthread_mutex_t mutexB;

// 執行緒函數：執行緒 1
void* threadFunc1(void* arg) {
    pthread_mutex_lock(&mutexA);
    cout << "Thread 1 locked mutexA" << endl;

    // 模擬某些處理
    sleep(1);

    pthread_mutex_lock(&mutexB);
    cout << "Thread 1 locked mutexB" << endl;

    // 解鎖
    pthread_mutex_unlock(&mutexB);
    pthread_mutex_unlock(&mutexA);

    cout << "Thread 1 released both locks" << endl;
    return nullptr;
}

// 執行緒函數：執行緒 2
void* threadFunc2(void* arg) {
    pthread_mutex_lock(&mutexB);
    cout << "Thread 2 locked mutexB" << endl;

    // 模擬某些處理
    sleep(1);

    pthread_mutex_lock(&mutexA);
    cout << "Thread 2 locked mutexA" << endl;

    // 解鎖
    pthread_mutex_unlock(&mutexA);
    pthread_mutex_unlock(&mutexB);

    cout << "Thread 2 released both locks" << endl;
    return nullptr;
}

int main() {
    // 初始化互斥鎖
    pthread_mutex_init(&mutexA, nullptr);
    pthread_mutex_init(&mutexB, nullptr);

    pthread_t thread1, thread2;

    // 創建執行緒
    pthread_create(&thread1, nullptr, threadFunc1, nullptr);
    pthread_create(&thread2, nullptr, threadFunc2, nullptr);

    // 等待執行緒結束
    pthread_join(thread1, nullptr);
    pthread_join(thread2, nullptr);

    // 銷毀互斥鎖
    pthread_mutex_destroy(&mutexA);
    pthread_mutex_destroy(&mutexB);

    return 0;
}