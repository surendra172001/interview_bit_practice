/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
 
bool solveUtil(TreeNode *A, vector<int> &path, int B) {
    if(A == NULL) {
        return false;
    }
    if(A->val == B) {
        path.push_back(A->val);
        return true;
    }
    if(solveUtil(A->left, path, B)) {
        path.push_back(A->val);
        return true;
    }
    if(solveUtil(A->right, path, B)) {
        path.push_back(A->val);
        return true;
    }
    return false;
}


vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> path;
    solveUtil(A, path, B);
    int half = path.size()/2;
    for(int i = 0; i < half; i++) {
        swap(path[i], path[path.size()-i-1]);
    }
    return path;
}

