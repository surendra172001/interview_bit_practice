
#include<set>

vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    set<int> sA(A.begin(), A.end());
    set<int> sB(B.begin(), B.end());
    set<int> sC(C.begin(), C.end());
    
    set<int> ans;
    
    for(int x : sA) {
        if(sB.find(x) != sB.end()) {
            ans.insert(x);
        } else if(sC.find(x) != sC.end()) {
            ans.insert(x);
        }
    }
    
    for(int x : sB) {
        if(ans.find(x) == ans.end()) {
            if(sC.find(x) != sC.end()) {
                ans.insert(x);
            }
        }
    }
    
    vector<int> a(ans.begin(), ans.end());
    return a;
}
