vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> st;
    int n = A.size();
    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        while(!st.empty() && st.top() >= A[i]) {
            st.pop();
        }
        if(st.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = st.top();
        }
        st.push(A[i]);
    }
    return ans;
}
