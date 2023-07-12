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
    // ITERATIVE USING TWO STACKS
    // left- right - root
    void postorder(TreeNode* cur, vector<int> &ans){
        if(cur == NULL) return;
        
        stack<TreeNode* > s1;
        stack<TreeNode* > s2;
        
        s1.push(cur);
        
        while(!s1.empty()){
            cur = s1.top();
            s2.push(cur);
            s1.pop();
            if(cur->left) s1.push(cur->left);
            if(cur->right) s1.push(cur->right);
        }
        
        while(!s2.empty()){
            ans.push_back(s2.top()-> val);
            s2.pop();
        }
        
    } 
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};