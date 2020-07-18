int Solution::longestValidParentheses(string str) {
    int maxLenValidParentheses = 0;
    stack<int> st;
    st.push(-1);
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '(') {
            st.push(i);
        } else {
            st.pop();
            if(!st.empty()) {
                maxLenValidParentheses = max(maxLenValidParentheses, i-st.top());
            } else {
                st.push(i);
            }
        }
    }
    return maxLenValidParentheses;
}
