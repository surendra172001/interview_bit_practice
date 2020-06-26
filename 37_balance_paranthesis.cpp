#include<map>

map<char, char> counterPart;

void initialize() {
    counterPart[')'] = '(';
    counterPart['}'] = '{';
    counterPart[']'] = '[';
}

int Solution::isValid(string A) {
    initialize();
    stack<char> st;
    for(char x : A) {
        if(x == '(' || x == '{' || x == '[') {
            st.push(x);
        } else {
            bool ans = false;
            while(!st.empty()) {
                char ch = st.top();
                // cout << ch << " " << x << endl;
                st.pop();
                if(counterPart[x] == ch) {
                    ans = true;
                    break;
                }
            }
            if(!ans) {
                return 0;
            }
        }
    }
    return st.empty();
}
