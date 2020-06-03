/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


int isBalancedUtil(TreeNode* A, bool &balanced) {
    if(A == NULL) {
        balanced = true;
        return 0;
    }
    bool b1 = false, b2 = false;
    int h1 = isBalancedUtil(A->left, b1);
    int h2 = isBalancedUtil(A->right, b2);
    if(b1 && b2 && (abs(h1-h2) <= 1)) 
        balanced = true;
    return 1 + max(h1, h2);
}
int Solution::isBalanced(TreeNode* A) {
    bool balanced = false;
    int x = isBalancedUtil(A, balanced);
    return (int) balanced;
}
