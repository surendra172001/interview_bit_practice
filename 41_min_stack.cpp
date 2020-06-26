vector<int> st;
int minM;


MinStack::MinStack() {
    st.clear();
    minM = INT_MAX;
}

void MinStack::push(int x) {
    minM = min(minM, x);
    st.push_back(x);
}

void MinStack::pop() {
    if(!st.empty()) {
        if(st[st.size()-1] == minM) {
            minM = st[0];
            for(int i = 1; i < st.size()-1; i++) {
                minM = min(minM, st[i]);
            }
        }
        st.pop_back();
        if(st.empty()) {
            minM = INT_MAX;
        }
    }
}

int MinStack::top() {
    if(st.size() == 0) {
        return -1;
    }
    return st[st.size()-1];
}

int MinStack::getMin() {
    if(st.size() == 0) {
        return -1;
    }
    return minM;
}

