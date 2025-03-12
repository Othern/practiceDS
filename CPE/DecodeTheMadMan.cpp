#include <iostream>
#include <vector>
#include <cctype>
using namespace std;
/*
發揮聯想力進行解碼，題目只有一組範例測試資料，就是輸入「k[r dyt I[o」
應輸出how are you
*/
int main() {
    vector<string> keyboard = {
        "1234567890-=",
        "qwertyuiop[]",
        "asdfghjkl;'",
        "zxcvbnm,./"
    };
    string line;
    while(getline(cin, line)){ // 讀取整行輸入
        for (char c : line) {
            if (c == ' ') {
                cout << ' '; // 保持空格
                continue;
            }

            char lowC = tolower(c);
            bool found = false;

            for (const string &row : keyboard) {
                for (size_t j = 0; j < row.size(); j++) {
                    if (row[j] == lowC) {
                        if (j >= 2) {
                            cout << row[j - 2];
                        }
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }
        }

        cout << endl; // 輸出換行
    }
    return 0;
}