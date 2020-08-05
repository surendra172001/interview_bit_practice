
int calPrefixLength(string &A, string &B) {
    int i = 0;
    for(; i < A.length() && i < B.length(); i++) {
        if(A[i] != B[i]) break;
    }
    return i;
}

string Solution::longestCommonPrefix(vector<string> &A) {
    string ans = A[0];
    for(int i = 1; i < A.size(); i++) {
        int r = calPrefixLength(A[i], A[i-1]);
        if(r < ans.length()) {
            ans = A[0].substr(0, r);
        }
    }
    return ans;
}


