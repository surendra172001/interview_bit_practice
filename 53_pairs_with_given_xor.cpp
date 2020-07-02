#include <set>
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    sort(A.begin(), A.end());
    set<int> s(A.begin(), A.end());
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int j = i;
        while(j < n && A[i] == A[j]) {
            j += 1;
        }
        j--;
        int key = A[i]^B;
        ans += (s.find(key) != s.end());
        i = j;
    }
    return ans/2;
}
