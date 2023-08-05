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
    vector<TreeNode*> generateTrees(int n) {
        return helper(1, n);
    }
    
     vector<TreeNode*> helper(int start, int end){
         vector<TreeNode*> list;
         // edge cases
         
         if(start > end){
             list.push_back(NULL);
             return list;
         }
         if(start == end){
             list.push_back(new TreeNode(start));
             return list;
         }
         // making trees
         for(int i = start; i <= end; i++){
             vector<TreeNode*> leftPossibleTree = helper(start, i-1);
             vector<TreeNode*> rightPossibleTree = helper(i+1, end);
             
             for(TreeNode* lRoot : leftPossibleTree){
                 for(TreeNode* rRoot : rightPossibleTree){
                    TreeNode* root = new TreeNode(i);
                     root->left = lRoot;
                     root->right = rRoot;
                     list.push_back(root);
                 }
             }
         }
         return list;
     }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
};