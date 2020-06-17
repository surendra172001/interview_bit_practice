int Solution::solve(string A) {
    int n = A.length();
    
    int ans = -1;
    
    for(int i = n-1; i > 0; i--) {
        if(A[0] == A[i]) {
            int l = 1, r = i-1;
            int cnt = 2;
            while(l < r && A[l] == A[r]) {
                cnt += 2;
                l++;
                r--;
            }
            
            //if length is odd include the middle character
            cnt += (l == r);
            if(cnt == i+1) {
                ans = cnt;
                break;
            }
        }
    }
    
    return (ans == -1 ? n-1 : n-ans);    
}
