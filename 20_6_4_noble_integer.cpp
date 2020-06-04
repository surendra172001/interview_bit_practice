#include<algorithm>

int Solution::solve(vector<int> &A) {
    int n = A.size();
    sort(A.begin(), A.end());
    
    vector<int> ans(n);
    ans[n-1] = 0;
    for(int i = n-2; i >= 0; i--) {
        ans[i] = (A[i] == A[i+1] ? ans[i+1] : n-i-1);
    }
    
    
    
    for(int i = 0; i < n; i++) {
        // cout << A[i] << " " << ans[i] << "\n";
        if(ans[i] == A[i]) return 1;
    }
    return -1;
}
