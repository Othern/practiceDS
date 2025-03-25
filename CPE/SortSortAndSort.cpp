# include <iostream>
# include <algorithm>
# include <vector>
/*
給你兩個整數 N (0<N<=10000), M (0<M<=10000)，
你要依照某些規則排序N個整數。先利用每個數字除以M的餘數由小到大排，
若排序中比較的兩數為一奇一偶且兩數除以M 的餘數相等，則奇數要排在偶數前面。
若兩奇數除以M餘數大小相等，則原本數值較大的奇數排在前面。
同樣的，若兩偶數除以M餘數大小相等，則較小的偶數排在前面。至於負數的餘數計算和 C 語言裡的定義相同，
即負數的餘數絕對不會大於零。例如 -100 MOD 3 = -1, -100 MOD 4 = 0 依此類推。
*/
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