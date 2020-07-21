
void longestIncreasingSubsequence(vector<int> &dp, vector<int> &A) {
    int n = A.size();
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(A[j] < A[i]) {
                dp[i] = max(dp[i], 1+dp[j]);
            }
        }
    }
}

void reverse(vector<int> &A) {
    int n = A.size();
    int half = n/2;
    for(int i = 0; i < half; i++) {
        swap(A[i], A[n-i-1]);
    }
}

int Solution::longestSubsequenceLength(const vector<int> &A) {
    vector<int> B = A;
    int n = A.size();
    vector<int> fdp(n, 1), bdp(n, 1);
    longestIncreasingSubsequence(fdp, B);
    reverse(B);
    longestIncreasingSubsequence(bdp, B);
    int maxM = 0;
    for(int i = 0; i < n; i++) {
        maxM = max(maxM, fdp[i]+bdp[n-i-1]-1);
    }
    return maxM;
}


