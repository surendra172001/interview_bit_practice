
vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    int n = A.size();
    vector<vector<int> > ans;
    vector<int> vis(n);
    for(int i = 0; i < n; i++) {
        if(vis[i] == 0) {
            vector<int> currComp;
            currComp.push_back(i+1);
            vis[i] = 1;
            string p = A[i];
            sort(p.begin(), p.end());
            for(int j = i+1; j < n; j++) {
                if(vis[j] == 0 && A[j].length() == A[i].length()) {
                    string q = A[j];
                    sort(q.begin(), q.end());
                    if(p == q) {
                        vis[j] = 1;
                        currComp.push_back(j+1);
                    }
                }
            }
            ans.push_back(currComp);
        }
    }
    return ans;
}

