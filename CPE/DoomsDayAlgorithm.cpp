/*
給日期，問那天星期幾
第一行有個T代表詢問的日期數(T<=100)
接下來會有T行，每行都有一組M、D分別代表月份和日期
輸出那天星期幾
test
9
1 6
2 28
4 5
5 26
8 1
11 1
12 25
12 31
3 9
output
Thursday
Monday
Tuesday
Thursday
Monday
Tuesday
Sunday
Saturday
Wednesday
由2011/1/ 6 Thu得知 2011/12/31 為星期五，以其作為基準點算偏移
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    int n;
    vector<int> month ={31,28,31,30,31,30,31,31,30,31,30,31};
    vector<string> week = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday","Saturday"};
    vector<pair<int,int>> data;
    while(cin >> n){
        cin.ignore();
        data.clear();
        for(int i=0; i<n; i++){
            int a, b;
            cin >> a >> b;
            data.push_back(pair<int,int>(a,b));
        }

        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=0; j < data[i].first -1; j++)sum += month[j];
            sum += data[i].second;
            // 由2011/1/ 6 星期四得知 2011/12/31 為星期五，以其作為基準點算偏移
            cout << week[(sum + 5)% 7] << endl;
            
        }
    }
    return 0;
}