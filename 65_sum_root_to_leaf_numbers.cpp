// /**
//  * Definition for binary tree
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */

const int MOD = (1e3)+3;

void sumNumbersUtil(TreeNode* A, int num, int &sum) {
    if(A == NULL) {
        return;
    }
    num = ((num*10)%MOD+A->val)%MOD;
    if(A->left == NULL && A->right == NULL) {
        sum = (sum+num)%MOD;
        return;
    }
    sumNumbersUtil(A->left, num, sum);
    sumNumbersUtil(A->right, num, sum);
}


int Solution::sumNumbers(TreeNode* A) {
    int sum = 0;
    sumNumbersUtil(A, 0, sum);
    return sum;
}

