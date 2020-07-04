/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 typedef pair<int, int> pii;
 
 
 void inorder(TreeNode* A, vector<pii> &elements, int levelNo) {
     if(A == NULL) {
         return;
     }
     inorder(A->left, elements, levelNo+1);
     elements.push_back({A->val, levelNo});
     inorder(A->right, elements, levelNo+1);
 }
 
int Solution::isSymmetric(TreeNode* A) {
    if(A == NULL) {
        return 1;
    }
    
    vector<pii> elements;
    
    inorder(A, elements, 0);
    
    int half = elements.size()/2;
    
    for(int i = 0; i < half; i++) {
        if((elements[i].first != elements[elements.size()-i-1].first )|| 
            (elements[i].second != elements[elements.size()-i-1].second)) {
            return 0;
        }
    }
    return 1;
}
