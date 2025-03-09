#include <iostream>
#include <vector>
#include <climits>  // For INT_MIN
using namespace std;
// dp method
int CatalanNumber(int n){
    if (n <= 1) return 1;

    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++) { // Loop from 2 to n
        for (int j = 0; j < i; j++) { // Corrected range for j
            dp[i] += dp[j] * dp[i - 1 - j]; // Correct formula
        }
    }

    return dp[n]; // Return dp[n], not dp[n+1]
}

int main(){
    for(int i = 0; i <= 10; i++){
        cout << CatalanNumber(i) << " ";
    }
    
    return 0;
}