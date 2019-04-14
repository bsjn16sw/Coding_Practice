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
    // TreeNodes pointed by t1 and t2 have to be same
    // to be symmetric.
    bool isSymmetricPart(TreeNode* t1, TreeNode* t2) {
        if(!t1){
            if(!t2) return true;
            return false;
        }
        else{
            if(!t2) return false;
            if(t1->val != t2->val)  return false;
            return isSymmetricPart(t1->left, t2->right) 
                && isSymmetricPart(t1->right, t2->left);
        }
    }
    
    bool isSymmetric(TreeNode* root) {
        if(!root)   return true;
        return isSymmetricPart(root->left, root->right);
    }
};
