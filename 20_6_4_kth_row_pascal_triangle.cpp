vector<int> Solution::getRow(int A) {
    if(A == 0)
        return vector<int>({1});
    vector<int> ans;
    int c = 1;
    int line = A+1;
    for (int i = 1; i <= line; i++)  {
        ans.push_back(c);
        c = c * (line - i) / i;
    } 
    return ans;
}
