string Solution::convert(string A, int B) {
    if(B <= 1) return A;
    int n = A.length();
    string ans;
    vector<string> rows(B);
    int r = 0, f = -1;
    for(int i = 0; i < n; i++) {
        rows[r] += A[i];
        if((r%B == 0) || (r==(B-1))) f = (f == 1 ? -1 : 1);
        r += f;
    }
    for(string s : rows) {
        ans += s;
    }
    return ans;
}
