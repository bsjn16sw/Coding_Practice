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
    int maxDepth(TreeNode* root) {
        TreeNode* tp = root;
        int leftDepth = 0, rightDepth = 0, subDepth = 0;
        
        // Edge case
        if(!tp) return 0;
        
        // If left-subtree exists, calculate the depth of it
        // by recursive call.
        if(tp->left)
            leftDepth = maxDepth(tp->left);
        
        // If right-subtree exists, calculate the depth of it
        // by recursive call.
        if(tp->right)
            rightDepth = maxDepth(tp->right);
        
        // If left and right subtree do not exist,
        // that meams, if it is leaf node, return the depth 1.
        if(!tp->left && !tp->right)
            return 1;
        
        // Depth of subtree is below.
        subDepth = max(leftDepth, rightDepth);
        
        return subDepth + 1;
    }
};
