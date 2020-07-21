int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    vector<vector<int> > dp(n, vector<int>(n, 0));
    
    for(int i = 0; i < n; i++) {
        dp[n-1][i] = A[n-1][i];
    }
    
    for(int i = n-2; i >= 0; i--) {
        dp[i][n-1] = A[i][n-1]+dp[i+1][n-1];
    }
    
    for(int i = n-2; i >= 0; i--) {
        for(int j = i; j >= 0; j--) {
            dp[i][j] = A[i][j] + max(dp[i+1][j], dp[i+1][j+1]);
        }
    }
    
    return dp[0][0];
}

