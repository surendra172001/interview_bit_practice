int minDistanceUtil(vector<vector<int> > &dp, string &A, string &B, int i, int j, int n, int m) {
    if(i > n || j > m) {
        return int(1e6);
    }
    if(i == n) {
        return m-j;
    }
    if(j == m) {
        return n-i;
    }
    
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    
    if(A[i] == B[j]) {
        return minDistanceUtil(dp, A, B, i+1, j+1, n, m);
    }
    
    int op1 = minDistanceUtil(dp, A, B, i+1, j, n, m);
    int op2 = minDistanceUtil(dp, A, B, i, j+1, n, m);
    int op3 = minDistanceUtil(dp, A, B, i+1, j+1, n, m);
    dp[i][j] = min(op1, op2);
    dp[i][j] = min(dp[i][j], op3);
    dp[i][j] += 1;
    return dp[i][j];
}

// int Solution::minDistance(string A, string B) {
//     int n = A.length(), m = B.length();
//     vector<vector<int> > dp(n, vector<int>(m, -1));
//     return minDistanceUtil(dp, A, B, 0, 0, n, m);
// }

int Solution::minDistance(string A, string B) {
    int n = A.length(), m = B.length();
    vector<vector<int> > dp(n+1, vector<int>(m+1, 0));
    
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(i == 0) {
                dp[i][j] = j;
            } else if(j == 0) {
                dp[i][j] = i;
            } else if(A[i-1] == B[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]);
                dp[i][j] = min(dp[i][j], dp[i][j-1]);
                dp[i][j] += 1;
            }
        }
    }
    
    return dp[n][m];
}
 
