/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode* root, vector<int> &inorder){
        if(!root) return;
        
        traverse(root->left, inorder);
        inorder.push_back(root->val);
        traverse(root->right, inorder);

    }
    bool isValidBST(TreeNode* root) {
        vector<int> inorder;
        traverse(root, inorder);
        int n = inorder.size();
        for(int i = 0 ; i< n-1; i++){
            if(inorder[i] >= inorder[i+1]) return false;
        }
        return true;
    }
};