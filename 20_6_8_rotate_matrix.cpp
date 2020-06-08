void Solution::rotate(vector<vector<int> >& A)
{
    int l = A.size();
    for (int i = 0; i < l / 2; i++) {
        A[i].swap(A[l - i - 1]);
    }
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < i; j++) {
            swap(A[i][j], A[j][i]);
        }
    }
}
