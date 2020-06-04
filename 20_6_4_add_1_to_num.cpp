
vector<int> Solution::plusOne(vector<int> &a) {
    int n = a.size();
    int carry = 1;
    for(int i = n-1; i >= 0; i--) {
        a[i] = a[i] + carry;
        carry = a[i]/10;
        a[i] %= 10;
    }
    if(carry == 1) {
        a.insert(a.begin(), 1);
        return a;
    }
    int i;
    for(i = 0; i < n && a[i] == 0; i++);
    i--;
    if(i < 0) 
        return a;
    else {
        vector<int> ans;
        i += 1;
        for(; i < n; i++) ans.push_back(a[i]);
        return ans;
    }
}

