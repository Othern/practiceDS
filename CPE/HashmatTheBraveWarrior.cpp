#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    int a, b;
    // 讀取至檔案結束，這種資料通常不會宣告檔案有多少筆，因此必須一直處理直到沒有資料為止
    while(cin >> a >> b){
        // 若把cin放進while判斷條件裡，cin會自動轉型成void*。
        // void* 是一種 指向任何類型的指標
        // 當檔案結束時，其值會變成NULL
        cout << abs(a - b) << endl;
    }
    return 0;
}