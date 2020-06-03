TreeNode* Solution::invertTree(TreeNode* A) {
    if(A == NULL) return A;
    A->left = invertTree(A->left);
    A->right = invertTree(A->right);
    TreeNode *temp = A->left;
    A->left = A->right;
    A->right = temp;
    return A;
}
