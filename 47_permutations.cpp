void permuteUtil(vector<vector<int> > &ans, vector<int> &A, vector<int> &v, int s) {
    if(A.size() == 0) {
        ans.push_back(v);
    }
    for(int i = 0; i < A.size(); i++) {
        int x = A[i];
        v.push_back(A[i]);
        A.erase(A.begin()+i);
        permuteUtil(ans, A, v, s+1);
        A.insert(A.begin()+i, x);
        v.pop_back();
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int> > ans;
    vector<int> v;
    permuteUtil(ans, A, v, 0);
    return ans;
}
