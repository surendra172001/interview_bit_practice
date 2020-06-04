vector<vector<int> > Solution::solve(int n) {
    if(n == 0) return vector<vector<int> >();
    vector<vector<int> > ans = vector<vector<int> >(n);
    ans[0].push_back(1);
    ans[1] = vector<int>({1, 1});
    for(int i = 2; i < n; i++) {
        vector<int> aux(i+1);
        int half = (i+1)/2;
        aux[0] = 1;
        aux[i] = 1;
        for(int j = 1; j < half; j++) {
            aux[j] = ans[i-1][j] + ans[i-1][j-1];
            aux[i-j] = aux[j];
        }
        if(i%2 == 0)
            aux[half] = ans[i-1][half] + ans[i-1][half-1];
        ans[i] = aux;
    }
    return ans;
}
