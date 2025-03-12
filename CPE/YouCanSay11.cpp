#include <iostream>
using namespace std;
/*
你的任務是，給你一個正整數 N，判定它是否是 11 的倍數。
*/
int main(){
    int a;
    while(cin >> a){
        cin.ignore();
        int temp = a, odd =0, even = 0;
        bool flag = 0;
        while(temp > 0){
            if(flag == 0)odd += temp %10;
            else even += temp % 10;
            flag = flag ? false : true;
            temp/=10;
        }
        if(odd == even) cout << "You can say 11."<< endl;
        else cout << "You can not say 11." << endl;
    }
    return 0;
}