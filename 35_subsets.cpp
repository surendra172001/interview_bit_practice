void subsetsUtil(vector<int>& A, vector<vector<int> >& res, 
                 vector<int>& subset, int index) 
{ 
    res.push_back(subset); 
    for (int i = index; i < A.size(); i++) { 
        subset.push_back(A[i]); 
        subsetsUtil(A, res, subset, i + 1); 
        subset.pop_back(); 
    } 
  
    return; 
} 
  
vector<vector<int> > Solution::subsets(vector<int>& A) 
{ 
    set<int> st(A.begin(), A.end());
    vector<int> v(st.begin(), st.end());
    vector<int> subset; 
    vector<vector<int> > res; 
    int index = 0; 
    subsetsUtil(v, res, subset, index); 
  
    return res; 
} 
  
