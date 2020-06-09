#include<bits/stdc++.h>
using namespace std;

void setRow(vector<vector<int> > &A, int r) {
    for(int i = 0; i < A[0].size(); i++) A[r][i] = 0;
}

void setCol(vector<vector<int> > &A, int c) {
    for(int i = 0; i < A.size(); i++) A[i][c] = 0;
}

void Solution::setZeroes(vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();
    set<int> rs, cs;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(!A[i][j]) {
                rs.insert(i);
                cs.insert(j);
            }
        }
    }
    
    for(int x : rs) setRow(A, x);
    for(int x : cs) setCol(A, x);

}
