
typedef vector<string> vs;
typedef vector<vector<string> > vvs;

bool isSafePos(vs &mat, int r, int c, int A) {
    //row movement
    for(int i = 0; i < A; i++) {
        if(i != c && mat[r][i] == 'Q') {
            return false;
        }
    }
    //column movement
    for(int i = 0; i < A; i++) {
        if(i != r && mat[i][c] == 'Q') {
            return false;
        }
    }
    int i = r+1, j = c+1;
    //bottom right movement
    while(i < A && j < A) {
        if(mat[i][j] == 'Q') {
            return false;
        }
        i += 1;
        j += 1;
    }
    i = r+1, j = c-1;
    //bottom left movement
    while(i < A && j >= 0) {
        if(mat[i][j] == 'Q') {
            return false;
        }
        i += 1;
        j -= 1;
    }
    i = r-1, j = c-1;
    //up left movement
    while(i >= 0 && j >= 0) {
        if(mat[i][j] == 'Q') {
            return false;
        }
        i -= 1;
        j -= 1;
    }
    i = r-1, j = c+1;
    //up right movement
    while(i >= 0 && j < A) {
        if(mat[i][j] == 'Q') {
            return false;
        }
        i -= 1;
        j += 1;
    }
    return true;
}


void solveNQueensUtil(vvs &ans, vs &mat, int r, int A) {
    // cout << r << " ";
    if(r == A) {
        ans.push_back(mat);
        return;
    }
    for(int i = 0; i < A; i++) {
        if(isSafePos(mat, r, i, A)) {
            mat[r][i] = 'Q';
            solveNQueensUtil(ans, mat, r+1, A);
            mat[r][i] = '.';
        }
    }
}

vector<vector<string> > Solution::solveNQueens(int A) {
    vvs ans;
    vs mat(A, string(A, '.'));
    for(int i = 0; i < A; i++) {
        mat[0][i] = 'Q';
        // cout << "\n" << i << "\n";
        solveNQueensUtil(ans, mat, 1, A);
        mat[0][i] = '.';
        // cout << "\nbelow " << i << "\n";
    }
    return ans;
}
