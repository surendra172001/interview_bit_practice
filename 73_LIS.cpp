// int Solution::lis(const vector<int> &A) {
//     int n = A.size();
//     vector<int> dp(n);
//     dp[0] = 1;
//     for(int i = 1; i < n; i++) {
//         dp[i] = 1;
//         for(int j = 0; j < i; j++) {
//             if(A[i] > A[j]) {
//                 dp[i] = max(dp[i], 1+dp[j]);
//             }
//         }
//     }
//     int maxM = INT_MIN;
//     for(int i = 0; i < n; i++) {
//         maxM = max(maxM, dp[i]);
//     }
//     return maxM;
// }




int Solution::lis(const vector<int> &A) {
    int n = A.size();
    vector<int> lis;
    lis.push_back(A[0]);
    for(int i = 1; i < n; i++) {
        if(A[i] < lis[0]) {
            lis[0] = A[i];
        } else if(A[i] > lis.back()) {
            lis.push_back(A[i]);
        } else {
            int x = lower_bound(lis.begin(), lis.end(), A[i])-lis.begin();
            lis[x] = A[i];
        }
    }
    return lis.size();
}

