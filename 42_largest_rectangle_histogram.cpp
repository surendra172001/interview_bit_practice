
int Solution::largestRectangleArea(vector<int> &A) {
    int n = A.size();
    stack<int> lsvStack;
    stack<int> rsvStack;
    vector<int> lsv(n);
    vector<int> rsv(n);
    for(int i = 0; i < n; i++) {
        while((!lsvStack.empty()) && A[lsvStack.top()] >= A[i]) {
            lsvStack.pop();
        }
        if(lsvStack.empty()) {
            lsv[i] = -1;
        } else {
            lsv[i] = lsvStack.top();
        }
        lsvStack.push(i);
    }
    
    for(int i = n-1; i >= 0; i--) {
        while((!rsvStack.empty()) && A[rsvStack.top()] >= A[i]) {
            rsvStack.pop();
        }
        if(rsvStack.empty()) {
            rsv[i] = n;
        } else {
            rsv[i] = rsvStack.top();
        }
        rsvStack.push(i);
    }
    int ans = INT_MIN;
    for(int i = 0; i < n; i++) {
        int size = rsv[i]-lsv[i]-1;
        ans = max(ans, size*A[i]);
    }
    
    return ans;
}
