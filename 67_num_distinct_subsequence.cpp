
int Solution::numDistinct(string A, string B) {
    int n = A.length(), m = B.length();
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dp[i][j] = dp[i-1][j];
            if(A[i-1] == B[j-1]) {
                dp[i][j] += dp[i-1][j-1];
            }
        }
    }
    return dp[n][m];
}
