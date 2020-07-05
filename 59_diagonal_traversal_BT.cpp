/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<map>

void solveUtil(TreeNode* A, map<int, vector<int> > &mp, int currLevel) {
    if(A == NULL) {
        return;
    }
    
    if(mp.find(currLevel) == mp.end()) {
        mp.insert({currLevel, vector<int>(1, A->val)});
    } else {
        mp[currLevel].push_back(A->val);
    }
    
    solveUtil(A->left, mp, currLevel+1);
    solveUtil(A->right, mp, currLevel);
}
 
vector<int> Solution::solve(TreeNode* A) {
    map<int, vector<int> > mp;
    solveUtil(A, mp, 0);
    vector<int> ans;
    for(pair<int, vector<int> > p : mp) {
        ans.insert(ans.end(), p.second.begin(), p.second.end());
    }
    return ans;
}




