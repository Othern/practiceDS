#include <iostream>
using namespace std;
/*
cnt: 紀錄「”」出現的次數
每次遇到「”」時，
若 cnt 為偶數：以「`」「`」取代
若 cnt 為奇數：以「’」「’」取代
*/
int main(){
    char c;
    bool flag = 0;
    // cin.get() 直到EOF為止
    while(cin.get(c)){
        if(c == '"' && flag){
            flag = 1;
            cout << "``";
        }
        else if(c == '"' && !flag){
            flag = 0;
            cout << "''";
        }
        else cout << c;
    }
    return 0;
}