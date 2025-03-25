/*
已知 N 的值，你必須求 G。G 的定義如下：
    其中 GCD(i,j) 為整數 i 和整數 j 的最大公因數。
    如果看不懂Sigma表示方式的話，G 的定義則如以下的程式碼：
        G=0;
        for(i=1;i<N;i++)
            for(j=i+1;j<=N;j++)
            {
            G+=GCD(i,j);
            }

GCD()為一個求兩個輸入數字的最大公因數的函數

輸入檔最多有 100 行的輸入。每一行有一個整數N (1<N<501)。N 的定義如題幹。輸入以含有一個 0 的一行作為結束，請不要處理這個 0。
*/
#include <iostream>
using namespace std;

// 通常大的放前面
int GCD(int i, int j){
    if(i%j == 0) return j;
    return GCD(j, i%j);

}
int main(){
    int N;
    while(cin >> N && N){
        int G = 0;
        for(int i = 1; i <= N; i++){
            for(int j = i+1; j <= N; j++){
                G += GCD(j,i); 
            }
        }
        cout << G << endl;
    }
    return 0;
}