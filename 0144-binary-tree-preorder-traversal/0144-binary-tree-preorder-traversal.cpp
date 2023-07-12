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
    // ITERATIVE 
     void preorder(TreeNode* root, vector<int> &ans){
        if(root == NULL) return;
        
        stack<TreeNode* > s;
         s.push(root);
        while(!s.empty()){
            TreeNode* topNode = s.top();
            s.pop();
            ans.push_back(topNode->val);
            if(topNode-> right) s.push(topNode->right);
            if(topNode-> left) s.push(topNode->left);
            
        } 
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};