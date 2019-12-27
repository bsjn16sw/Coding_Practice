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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Check if two root nodes are null or not.
        if(!p){
            if(!q)  return true;
            else    return false;
        }
        else{
            if(!q)  return false;
            else{
                // If two root nodes are not null,
                // check values of root nodes.
                if(p->val != q->val)    return false;

                // If values of root nodes are same,
                // check left/right subtrees.
                bool leftValid = false;
                bool rightValid = false;
                
                // Check left subtree
                if(p->left){
                    if(q->left) leftValid = isSameTree(p->left, q->left);
                    else        leftValid = false;
                }
                else{
                    if(q->left) leftValid = false;
                    else        leftValid = true;
                }
                // If left subtree is already different,
                // there is no need to check right subtree.
                if(!leftValid)  return false;
                
                // Check right subtree
                if(p->right){
                    if(q->right)    rightValid = isSameTree(p->right, q->right);
                    else            rightValid = false;
                }
                else{
                    if(q->right)    rightValid = false;
                    else            rightValid = true;
                }
                if(!rightValid) return false;
                else            return true;
            }
        }
    }
};
