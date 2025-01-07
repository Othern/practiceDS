#include <iostream>
#include <pthread.h>
#include <queue>
#include <unistd.h> // for sleep()

using namespace std;

// 共享資源
queue<int> buffer;                // 資料緩衝區
const int BUFFER_SIZE = 5;        // 緩衝區最大大小

// 同步工具
pthread_mutex_t mutexBuffer;      // 互斥鎖
pthread_cond_t condNotEmpty;      // 條件變數：緩衝區不為空
pthread_cond_t condNotFull;       // 條件變數：緩衝區未滿

// 生產者函數
void* producer(void* arg) {
    int data = 0; // 生產的資料
    while (true) {
        pthread_mutex_lock(&mutexBuffer);

        // 如果緩衝區已滿，等待消費者消費
        while (buffer.size() >= BUFFER_SIZE) {
            cout << "Producer: Buffer is full, waiting..." << endl;
            // 需要搭配mutexLock才可以使用
            pthread_cond_wait(&condNotFull, &mutexBuffer);
        }

        // 生產資料並放入緩衝區
        buffer.push(data);
        cout << "Producer: Produced data " << data << endl;
        data++;

        // 通知消費者有新的資料
        pthread_cond_signal(&condNotEmpty);

        pthread_mutex_unlock(&mutexBuffer);

        sleep(1); // 模擬生產的時間間隔
    }
    return nullptr;
}

// 消費者函數
void* consumer(void* arg) {
    while (true) {
        pthread_mutex_lock(&mutexBuffer);

        // 如果緩衝區為空，等待生產者生產
        while (buffer.empty()) {
            cout << "Consumer: Buffer is empty, waiting..." << endl;
            // 需要搭配mutexLock才可以使用，系統會先release mutexBuffer
            // thread 才會卡在condNotEmpty 變數
            pthread_cond_wait(&condNotEmpty, &mutexBuffer);
        }

        // 從緩衝區取出資料
        int data = buffer.front();
        buffer.pop();
        cout << "Consumer: Consumed data " << data << endl;

        // 通知生產者緩衝區有空間
        pthread_cond_signal(&condNotFull);

        pthread_mutex_unlock(&mutexBuffer);

        sleep(2); // 模擬消費的時間間隔
    }
    return nullptr;
}

int main() {
    // 初始化互斥鎖和條件變數
    pthread_mutex_init(&mutexBuffer, nullptr);
    pthread_cond_init(&condNotEmpty, nullptr);
    pthread_cond_init(&condNotFull, nullptr);

    // 創建生產者和消費者執行緒
    pthread_t producerThread, consumerThread;
    pthread_create(&producerThread, nullptr, producer, nullptr);
    pthread_create(&consumerThread, nullptr, consumer, nullptr);

    // 等待執行緒結束（此範例中，執行緒不會結束）
    pthread_join(producerThread, nullptr);
    pthread_join(consumerThread, nullptr);

    // 銷毀互斥鎖和條件變數
    pthread_mutex_destroy(&mutexBuffer);
    pthread_cond_destroy(&condNotEmpty);
    pthread_cond_destroy(&condNotFull);

    return 0;
}