#include<stack>
#define ll long long

int Solution::maxSpecialProduct(vector<int> &a) {
    const int MOD = 1000000007;
    int n = a.size();
    vector<int> left(n, 0), right(n, 0);
    
    stack<int> ls;
    ls.push(0);
    left[0] = 0;
    for(int i = 1; i < n; i++) {
        while((!ls.empty()) && (a[ls.top()] <= a[i])) ls.pop();
        left[i] = (ls.empty() ? 0 : ls.top());
        ls.push(i);
    }
    
    stack<int> rs;
    rs.push(n-1);
    right[n-1] = 0;
    for(int i = n-2; i >= 0; i--) {
        while((!rs.empty()) && (a[rs.top()] <= a[i])) rs.pop();
        right[i] =  (rs.empty() ? 0 : rs.top());
        rs.push(i);
    }
    
    ll maxM = -1;
    for(int i = 0; i < n; i++) 
        maxM = max(maxM, left[i] *1LL* right[i]);

    return maxM%MOD;
}

