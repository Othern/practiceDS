#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
/*
Vito Deadstone 在紐約有非常多親戚，他希望在紐約找到一間房子
該房子到各家親戚的距離相加之總和最小
input 第一筆為長度 , 第二筆之後為各家的街號
關鍵 : 當Vito Deadstone 在median 時與其他親戚距離最小
*/

int main(){
    int n;
    int k;
    vector<int> data;
    cin >> n;
    for(int i=0; i<n;i++){
        cin >> k;
        data.push_back(k);
    }
    sort(data.begin(),data.end());
    int sum = 0;
    for(int i =0; i< n; i++){
        sum += abs(data[n/2] - data[i]);
    }
    cout << sum;
    return 0;
}