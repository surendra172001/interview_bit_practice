int Solution::candy(vector<int> &A) {
    int n = A.size();
    vector<int> cc(n, 1);
    for(int i = 1; i < n; i++) {
        if(A[i] > A[i-1]) {
            cc[i] = cc[i-1]+1;
        }
    }
    
    for(int i = n-2; i >= 0; i--) {
        if(A[i] > A[i+1]) {
            cc[i] = max(cc[i], 1+cc[i+1]);
        }
    }
    
    int sum = 0;
    
    for(int i = 0; i < n; i++) {
        sum += cc[i];
    }
    
    return sum;
}


