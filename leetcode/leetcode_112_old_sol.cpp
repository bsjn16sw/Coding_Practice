// April 22, 2019

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> sums;
    
    void calcSum(TreeNode* root, int curSum) {
        // If gets to leaf node, push_back() to sums.
        if(!root->left && !root->right){
            sums.push_back(curSum);
            return;
        }
        
        // Depth First Search
        if(root->left)  calcSum(root->left, curSum + root->left->val);
        if(root->right) calcSum(root->right, curSum + root->right->val);
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)   return false;
        calcSum(root, root->val);
        for(int i=0; i<sums.size(); i++)
            if(sums[i] == sum)  return true;
        return false;
    }
};
