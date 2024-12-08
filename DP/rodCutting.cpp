#include <iostream>
#include <vector>
#include <climits>  // For INT_MIN
using namespace std;

int rodCut(int n, const vector<int>& prices) {
    vector<int> dp(n + 1, 0); // dp[i] 表示長度為 i 的鋼條的最大價值

    // 動態規劃填表
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i] = max(dp[i], prices[j - 1] + dp[i - j]);
        }
    }

    return dp[n];
}


int main() {
    int n = 4; // 鋼條的總長度
    int data[] = {1, 5, 8, 9};
    vector<int> prices;
    for(int i=0; i < 4; i++) prices.push_back(data[i]); // 每個長度對應的價格

    cout << "Maximum value: " << rodCut(n, prices) << endl;

    return 0;
}