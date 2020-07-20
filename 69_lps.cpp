
int solveUtil(vector<vector<int> > &dp, string &A, int i, int j, int n) {
    // cout << i << " " << j << endl;
    if(i < 0 || j >= n || i > j) return 0;
    if(i == j) return 1;
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    int ans = 0;
    if(A[i] == A[j]) {
        ans = solveUtil(dp, A, i+1, j-1, n)+2;
    } else {
        ans = max(solveUtil(dp, A, i, j-1, n), solveUtil(dp, A, i+1, j, n));
    }
    dp[i][j] = ans;
    return dp[i][j];
}

int Solution::solve(string A) {
    int n = A.length();
    vector<vector<int> > dp(n, vector<int>(n, -1));
    return solveUtil(dp, A, 0, n-1, n);
}
