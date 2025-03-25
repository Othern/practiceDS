#include <iostream>
using namespace std;
int main(){
    int n;
    while(cin >> n){
        int a,b, result;
        for(int i = 0; i< n; i++){
            result = 0;
            cin  >> a >> b;
            a = (a % 2 == 1) ? a : a+1;
            while(a <= b){
                result += a;
                a +=2;
            }
            cout << result << endl;
        }
    }
    return 0;
}