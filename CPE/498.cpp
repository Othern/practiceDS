#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

int main() {
    string line;
    
    while (true) {
        cout << "請輸入 x (或按 Ctrl+D 結束): ";
        if (!getline(cin, line) || line.empty()) break; // 偵測 EOF 或空行結束
        
        int x;
        stringstream ss_x(line);
        if (!(ss_x >> x)) {
            cout << "輸入錯誤，請重新輸入 x！\n";
            continue;
        }

        cout << "請輸入多項式係數 (以空格分開): ";
        if (!getline(cin, line) || line.empty()) break;

        stringstream ss_coeff(line);
        vector<int> cs;
        int coeff;
        while (ss_coeff >> coeff) {
            cs.push_back(coeff);
        }

        if (cs.empty()) {
            cout << "未輸入任何係數，請重新輸入！\n";
            continue;
        }

        int result = 0;
        int n = cs.size();
        
        // 計算導數後代入 x
        for (int i = 1; i < n; i++) { // i=0 的項目導數為 0，不需計算
            result += cs[i] * i * pow(x, i - 1);
        }

        cout << "結果: " << result << endl << endl;
    }

    cout << "程式結束！" << endl;
    return 0;
}