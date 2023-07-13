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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL) return result;
        
        queue<TreeNode*> nodes;
        nodes.push(root);
        bool leftToRight = true;
        
        while(!nodes.empty()){
            int size = nodes.size();
            vector<int>  row(size);
            
            for(int i = 0 ; i < size; i++){
                TreeNode* temp = nodes.front();
                nodes.pop();
                
                int index = leftToRight ? i : (size-1-i);
                
                row[index] = temp->val;
                if (temp -> left) {
                  nodes.push(temp -> left);
                }
               if (temp -> right) {
                  nodes.push(temp -> right);
                }
            }
         // after this level
        leftToRight = !leftToRight;
        result.push_back(row);
           
        }
        
    return result;
    }
};