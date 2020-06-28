
string Solution::solve(string A) {
    int n = A.length();
    int cnt[26] = {};
    int r = 0;
    string ans;
    for(int i = 0; i < n; i++) {
        cnt[A[i]-'a'] += 1;
        while(r <= i && cnt[A[r]-'a'] > 1) {
            r++;
        }
        if(r > i) {
            ans += '#';
        } else {
            ans += A[r];
        }
    }
    return ans;
}
