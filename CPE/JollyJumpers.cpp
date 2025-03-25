#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
/*
有n個整數的序列我們稱為jolly jumper，如果相鄰的2個數其差的絕對值恰好為1到n-1。例如：

1 4 2 3

就是jolly jumper（n=4）。因為相鄰2數的差的絕對值為3,2,1，就是1到n-1。但是

1 4 2 -1 6 

不是jolly jumper（n=5）。因為相鄰2數的差的絕對值為3,2,3,7，並非1到n-1。

你的任務是寫一個程式來判斷一個整數序列是否為jolly jumper。
*/
int main(){
    int n, a;
    while(cin >> n){
        if(n == 1) {  // Special case when n = 1, as there are no differences to check
            cout << "Jolly" << endl;
            continue;
        }

        vector<bool> d(n, false);  // We only need n-1 elements for differences 1 to n-1
        vector<int> data;
        bool flag = true;

        // Read the input data
        for(int i = 0; i < n; i++){
            cin >> a;
            data.push_back(a);
        }

        // Check the absolute differences between adjacent numbers
        for(int i = 1; i < n; i++){
            int jump = abs(data[i] - data[i-1]);
            // We are interested in differences from 1 to n-1
            if(jump >= 1 && jump <= n-1 && !d[jump-1]) {  
                d[jump-1] = true;
            } else {
                cout << "Not Jolly" << endl;
                flag = false;
                break;
            }
        }

        // If all differences are valid, the sequence is jolly
        if(flag) {
            cout << "Jolly" << endl;
        }
    }
    return 0;
}