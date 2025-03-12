#include <iostream>
#include <unordered_map>
#include <cctype>
using namespace std;
int main(){
    int n;  
    while(cin >> n){// 讀取行數
        cin.ignore(); // 忽略換行，防止影響 `getline()`

        unordered_map<char, int> count;
        int len = 0;
        // 讀取 n 行輸入
        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);  // 讀取整行輸入

            for (char c : line) {
                if (isalpha(c)) {  // 只統計字母
                    char t = toupper(c);
                    count[t]++;
                    len++;
                }
            }
        }

        // 按出現次數遞減輸出
        while (len > 0) {
            for (char c = 'A'; c <= 'Z'; c++) {
                if (count.find(c) != count.end() && count[c] == len) {
                    cout << c << " " << count[c] << endl;
                }
            }
            len--;
        }
    }

    return 0;
}