int Solution::bulbs(vector<int> &A) {
    
    int n = A.size();
    int switchCnt = 0;
    int x = 0;
    for(int i = 0; i < n; i++) {
        if(A[i] == x) {
            switchCnt += 1;
            x = 1-x;
        }
    }
    
    return switchCnt;
}



// int Solution::bulbs(vector<int> &A) {
// if(A.size()==0)return 0;
// int ans=0;
// for(int i = 0;i<A.size();i++){
// if(A[i]==0 and ans%2==0)ans++;
// if(A[i]==1 and ans%2==1)ans++;
// }
// return ans;
// }
