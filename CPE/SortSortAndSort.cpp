# include <iostream>
# include <algorithm>
# include <vector>
using namespace std;
int m, n;
// 兩數比較排前面的要設為true
bool cmp(int a, int b){
    int a1 = abs(a%2);
    int b1 = abs(b%2);
    // odd 要在前面 
    if(a%m != b%m) return a%m < b%m;
    else if(a1 != b1)   return a1 > b1;
    else if(a1 == 1)    return a > b;
    else return a < b;

}
int main(){
    vector<int> data;
    while(cin >> n >> m){
        data.clear();
        for(int i=0; i<n; i++){
            int temp;
            cin >> temp;
            data.push_back(temp);
        } 
        sort(data.begin(), data.end(), cmp);
        for(int i=0; i<n; i++){
            cout << data[i] << endl;
        }
    }
    return 1;
}