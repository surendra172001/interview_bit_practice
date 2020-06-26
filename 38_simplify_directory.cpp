string Solution::simplifyPath(string A) {
    int n = A.length();
    stack<string> st;
    for(int i = 0; i < n;) {
        while(i < n && A[i] == '/') {
            i++;
        }
        if(i >= n) {
            continue;
        }
        string a;
        while(i < n && A[i] != '/') {
            a += A[i];
            i++;
        }
        // cout << a << endl;
        if(a == "..") {
            if(!st.empty()) {
                st.pop();
            }
        } else if (a != ".") {
            st.push(a);
        }
    }
    string ans;
    stack<string> st1;
    while(!st.empty()) {
        string a = "/";
        a += st.top();
        st1.push(a);
        st.pop();
    }
    while(!st1.empty()) {
        ans += st1.top();
        st1.pop();
    }
    if(ans.length() == 0) {
        ans = "/";
    }
    return ans;
}

