/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* buildTreeUtil(vector<int> &A, vector<int> &B, int s, int e, int &idx) {
    if(s > e) {
        return NULL;
    }
    int val = B[idx];
    TreeNode *newNode = new TreeNode(B[idx]);
    idx--;
    if(s == e) {
        return newNode;
    }
    
    int pivot = -1;
    for(int i = s; i <= e; i++) {
        if(A[i] == val) {
            pivot = i;
            break;
        }
    }
    
    newNode->right = buildTreeUtil(A, B, pivot+1, e, idx);
    newNode->left = buildTreeUtil(A, B, s, pivot-1, idx);
    return newNode;
}

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int idx = B.size()-1;
    return buildTreeUtil(A, B, 0, A.size()-1, idx);
}

