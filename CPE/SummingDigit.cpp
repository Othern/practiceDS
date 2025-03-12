#include <iostream>

using namespace std;
int main(){
    
    int num;
    int sum;
    while(cin >> num){
        sum = 0;
        if(num == 0)break;
        else if(num < 10){
            cout << num;
            continue;
        }
        

        while(num >= 10){
            sum = 0;
            while(num > 0){
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }
        cout <<  sum << endl;

    }
    
    return 0;
}