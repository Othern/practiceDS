#include <iostream>

using namespace std;


/*
給兩個十進位數正整數，計算兩數相加過程中產生的進位次數
若兩數皆為0，表示結束
*/

int main(){
    int a, b;
    int a1, b1, carry,count;
    while(cin >> a >> b && ( a!= 0 || b !=0 )){
        count = 0;
        carry = 0;
        while(a > 0 || b > 0){
            a1 = a % 10;
            b1 = b % 10;
            if(a1 + b1 + carry >= 10){
                count++;
                carry = 1;
            } 
            else carry = 0;
            a /= 10;
            b /= 10; 
        }
        cout << count << " carry operations" << endl; 
    }
    return 0;
}