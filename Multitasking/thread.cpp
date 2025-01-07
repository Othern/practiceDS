#include <iostream>
#include <pthread.h>
#include <vector>

using namespace std;

// 共享資源
long long sum = 0;           // 總和
long long squareSum = 0;     // 平方和
pthread_mutex_t mutexSum;    // 用於同步的互斥鎖

// 緒函數：計算總和
//void* 是一種通用指標類型，稱為 「不定型指標」（generic pointer）。
void* calculateSum(void* arg) {
    // 轉型為 vector<int>* 後解引用
    vector<int>* numbers = (vector<int>*)arg;
    long long localSum = 0;
    for (int num : *numbers) {
        localSum += num;
    }
    
    // 使用互斥鎖保護共享資源
    pthread_mutex_lock(&mutexSum);
    sum += localSum;
    pthread_mutex_unlock(&mutexSum);
    
    return nullptr;
}

// 緒函數：計算平方和
void* calculateSquareSum(void* arg) {
    vector<int>* numbers = (vector<int>*)arg;
    long long localSquareSum = 0;
    for (int num : *numbers) {
        localSquareSum += num * num;
    }
    
    // 使用互斥鎖保護共享資源
    pthread_mutex_lock(&mutexSum);
    squareSum += localSquareSum;
    pthread_mutex_unlock(&mutexSum);
    
    return nullptr;
}

int main() {
    // 測試數據
    vector<int> numbers = {1, 2, 3, 4, 5};
    
    // 初始化互斥鎖
    pthread_mutex_init(&mutexSum, nullptr);
    
    // 創建執行緒
    pthread_t thread1, thread2;
    pthread_create(&thread1, nullptr, calculateSum, &numbers);
    pthread_create(&thread2, nullptr, calculateSquareSum, &numbers);
    
    // 等待thread 結束
    pthread_join(thread1, nullptr);
    pthread_join(thread2, nullptr);
    
    // 銷毀 mutex lock
    pthread_mutex_destroy(&mutexSum);
    
    // 輸出結果
    cout << "Sum: " << sum << endl;
    cout << "Square Sum: " << squareSum << endl;
    
    return 0;
}