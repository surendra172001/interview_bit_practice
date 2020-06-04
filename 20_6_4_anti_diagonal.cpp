vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int n = A.size();
    vector<vector<int> > ans;
    for(int i = 0; i < n-1; i++) {
        int x = 0, y = i;
        vector<int> aux;
        while(x < n && y >= 0) {
            aux.push_back(A[x][y]);
            x++, y--;
        }
        ans.push_back(aux);
    }
    
    for(int i = 0; i < n; i++) {
        int x = i, y = n-1;
        vector<int> aux;
        while(x < n && y >= 0) {
            aux.push_back(A[x][y]);
            x++, y--;
        }
        ans.push_back(aux);
    }
    
    return ans;
}
