
bool solveUtil(vector<vector<int> > &A, vector<vector<int> > &ans, int r, int c) {
    if(r == A.size()-1 && c == A.size()-1) {
        ans[A.size()-1][A.size()-1] = 1;
        return true;
    }
    if(r >= A.size() || c >= A.size() || A[r][c] == 0) {
        return false;
    }
    ans[r][c] = 1;
    if(solveUtil(A, ans, r+1, c)) {
        return true;
    }
    if(solveUtil(A, ans, r, c+1)) {
        return true;
    }
    ans[r][c] = 0;
    return false;
}

vector<vector<int> > Solution::solve(vector<vector<int> > &A) {
    vector<vector<int> > ans(A.size(), vector<int>(A.size()));
    bool a = solveUtil(A, ans, 0, 0);
    return ans;
}
