#include <iostream>
#include <unordered_map>
/*
給定兩個由小寫字母組成的字串a和b。
印出最長的小寫字串x，使得x經過重新排列後為a的子序列，且x經過重新排列後為b的子序列。

對於每組輸入，輸出本題要求a和b的x
如果有多組符合的x
請印出字母順序由小到大排列的那一個。
*/
using namespace std;

int main(){
    string a;
    string b;
    unordered_map<char, int> countA, countB;
    
    while(getline(cin, a) && getline(cin, b)){
        countA.clear();
        countB.clear();
        for(int i=0; i < a.size(); i++) countA[a[i]]++; // O(n)
        for(int i=0; i < b.size(); i++) countB[b[i]]++; // O(n)
        for(char c = 'a'; c <= 'z'; c++){
            int t = min(countA[c], countB[c]);
            for(int i =0; i<t; i++) cout << c;
        } // (O(1 * n))
        cout << endl;
    }
    return 0;
}