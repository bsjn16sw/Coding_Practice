// April 2, 2020

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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)   return false;
        
        if(!root->left && !root->right)
            return sum == root->val;
        
        bool temp = false;
        if(root->left)
            temp = hasPathSum(root->left, sum - root->val);
        
        // If left subtree got true flag,
        // there is no need to check right subtree.
        if(temp)    return true;
        
        if(root->right)
            return hasPathSum(root->right, sum - root->val);
        else
            return false;
    }
};