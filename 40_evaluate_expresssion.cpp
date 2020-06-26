
int stringToNum(string strNum) {
    int sign = 1;
    if(strNum[0] == '-') {
        strNum = strNum.substr(1, strNum.length()-1);
        sign = -1;
    }
    int n = (strNum.length());
    int p = pow(10, n-1);
    int result = 0;
    for(char x : strNum) {
        int dig = (int)(x-'0');
        result += dig*p;
        p /= 10;
    }
    result = sign * result;
    return result;
}

int evaluate(int x, int y, char operand) {
    switch(operand) {
        case '+':
            return x+y;
        case '-':
            return x-y;
        case '*':
            return x*y;
        case '/':
            return x/y;
    }
    return 0;
}

inline bool isDig(char c) {
    return 48 <= c && c <= 57;
}

int Solution::evalRPN(vector<string> &A) {
    if(A.size() == 1) {
        if(A[0] == "*" || A[0] == "/" || A[0] == "+" || A[0] == "-") {
            return 0;
        } else {
            return stringToNum(A[0]);
        }
    }
    stack<int> st;
    for(string s : A) {
        if(s == "*" || s == "/" || s == "+" || s == "-") {
            if(st.size() < 2) return 0;
            int y = st.top();
            st.pop();
            int x = st.top();
            st.pop();
            int result = evaluate(x, y, s[0]);
            st.push(result);
        } else {
            int num = stringToNum(s);
            st.push(num);
        }
    }
    return st.top();
}
