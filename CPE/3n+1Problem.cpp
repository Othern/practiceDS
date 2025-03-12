#include <iostream>
/*
考慮以下的演算法：

1.         輸入 n
2.         印出 n
3.         如果 n = 1 結束
4.         如果 n 是奇數 那麼 n=3*n+1
5.         否則 n=n/2
6.         GOTO 2

例如輸入 22, 得到的數列： 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1 
據推測此演算法對任何整數而言會終止 (當列印出 1 的時候)。雖然此演算法很簡單，但以上的推測是否真實卻無法知道。然而對所有的n ( 0 < n < 1,000,000 )來說，以上的推測已經被驗證是正確的。 
給一個輸入 n ,透過以上的演算法我們可以得到一個數列（1作為結尾）。此數列的長度稱為n的cycle-length。上面提到的例子, 22 的 cycle length為 16. 
問題來了：對任2個整數i，j我們想要知道介於i，j（包含i，j）之間的數所產生的數列中最大的 cycle length 是多少。
*/
using namespace std;
int main(){
    int a,b;
    while(cin >> a >> b){
        cin.ignore();
        int length = 0;
        if(a > b) swap(a,b);
        for(int i = a; i <= b; i++){
            int temp = i, l = 1;
            while(temp != 1){
                l++;
                // condition ? (if value) : (else value)
                temp = (temp %2 == 1 ) ? temp * 3 +1 : temp / 2;
            }
            length = max(l,length);
        }
        cout << length << endl;
    }
    return 0;
}