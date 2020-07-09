

bool hasPathSumUtil(TreeNode* A, int sum, int B) {
    if(A == NULL) {
        return false;
    }
    sum += A->val;
    if(A->left == NULL && A->right == NULL) {
        if(sum == B) {
            return true;
        } else {
            return false;
        }
    }
    if(hasPathSumUtil(A->left, sum, B)) {
        return true;
    }
    if(hasPathSumUtil(A->right, sum, B)) {
        return true;
    }
    return false;
}

int Solution::hasPathSum(TreeNode* A, int B) {
    return hasPathSumUtil(A, 0, B);
}
