vector<vector<int> > Solution::generateMatrix(int A) {
    int n = A;
    vector<vector<int> > ans = vector< vector<int> >(A, vector<int>(A));
    int cnt = 1;
    for(int r = 0; r < A/2; r++) {
        for(int j = r; j < n-r; j++) ans[r][j] = cnt++;
        for(int j = r+1; j < n-r; j++) ans[j][n-r-1] = cnt++;
        for(int j = n-r-2; j >= r; j--) ans[n-r-1][j] = cnt++;
        for(int j = n-r-2; j > r; j--) ans[j][r] = cnt++;
    }
    if(A%2 == 1) {
        ans[A/2][A/2] = cnt++;
    }
    return ans;
}
