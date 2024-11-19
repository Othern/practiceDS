#include <iostream>
using namespace std;

int com(int m,int n){
    if(m < n) return 0;
    if(n == 0) return 1;
    return com(m -1, n) + com(m-1, n-1);
}
int comDP(int m, int n){
    vector< vector<int> > dp(m+1,vector<int>(n+1,0));
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(j == 0) dp[i][j] = 1;
            else if(i < j) break;
            else{
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            }
        }
    }
    return dp[m][n];
}
int main(){
 //cout<< combination(5,3);
 cout<< comDP(5,3);
}