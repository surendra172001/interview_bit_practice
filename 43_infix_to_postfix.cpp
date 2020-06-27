
int precedence(char ch) {
    switch(ch) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
    return 0;
}


string Solution::solve(string A) {
    stack<char> st;
    string ans;
    for(char ch : A) {
        if(ch == '(') {
            st.push(ch);
        } else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            while(!st.empty() && st.top() != '(' && precedence(st.top()) >= precedence(ch)) {
                ans += st.top();
                st.pop();
            }
            st.push(ch);
        } else if(ch == ')') {
            while((!st.empty()) && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop();
        } else {
            ans += ch;
        }
    }
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }
    return ans;
}
