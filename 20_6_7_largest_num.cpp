
bool cmp(vector<int> &a, vector<int> &b) {
    int n = a.size() + b.size();
    vector<int> c, d;
    c.insert(c.end(), b.begin(), b.end());
    c.insert(c.end(), a.begin(), a.end());
    d.insert(d.end(), a.begin(), a.end());
    d.insert(d.end(), b.begin(), b.end());
    for(int i = 0; i < c.size(); i++) {
        if(c[i] != d[i]) {
            return d[i] > c[i];
        }
    }
    return true;
}
string Solution::largestNumber(const vector<int> &A) {
    vector<vector<int> > v(A.size());
    for(int i = 0; i < A.size(); i++) {
        int temp = A[i];
        vector<int> aux;
        while(temp) {
            aux.push_back(temp%10);
            temp /= 10;
        }
        vector<int>::reverse_iterator rit1 = aux.rbegin();
        while(rit1 != aux.rend()) {
            v[i].push_back(*rit1);
            rit1++;
        }
    }
    string ans;
    sort(v.begin(), v.end(), cmp);
    for(vector<int> a : v) {
        for(int x : a) ans += (char)(x + 48);
    }
    int i = 0;
    while(i < ans.length() && ans[i] == '0') i++;
    if(i >= ans.length()) return string("0");
    return ans.substr(i, ans.length()-i);
}

