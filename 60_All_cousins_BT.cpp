/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<queue>

vector<int> Solution::solve(TreeNode* A, int B) {
    if(A->val == B) {
        return vector<int>();
    }
    int currLevel = 0;
    queue<pair<TreeNode*, int> > q;
    q.push({A, 0});
    int bLevel = -1;
    while(!q.empty()) {
        TreeNode *newNode = q.front().first;
        int currLevel  = q.front().second;
        q.pop();
        if(bLevel == -1) {
            if(newNode->left && (newNode->left->val == B)) {
                bLevel = currLevel+1;
            } else if(newNode->right && (newNode->right->val == B)) {
                bLevel = currLevel+1;
            } else {
                if(newNode->left) {
                    q.push({newNode->left, currLevel+1}); 
                }
                if(newNode->right) {
                    q.push({newNode->right, currLevel+1}); 
                }
            }
        } else {
            if(currLevel == bLevel) {
                q.push({newNode, currLevel});
                break;
            }
            if(newNode->left) {
                q.push({newNode->left, currLevel + 1});
            }
            if(newNode->right) {
                q.push({newNode->right, currLevel + 1});
            }
        }
    }
    vector<int> ans;
    while(!q.empty()) {
        ans.push_back(q.front().first->val);
        q.pop();
    }
    
    return ans;
}

