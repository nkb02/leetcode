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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        int cur = root->val;
        if(cur <p->val && cur < q->val){
            // go left
            return lowestCommonAncestor(root->right, p, q);
        }
        
        if(cur > p->val && cur > q->val){
            // go right
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;
    }
};