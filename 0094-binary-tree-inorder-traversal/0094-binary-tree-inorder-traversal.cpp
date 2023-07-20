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
private:   
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        TreeNode* cur = root;
        while(cur != NULL)
        {
            // CASE - I 
            // IF LEFT TREE IS EMPTY
            if(cur-> left == NULL)
            {
                inorder.push_back(cur-> val);
                cur = cur-> right;
            }
            // CASE - II 
            // IT HAS A LEFT SUB TREE
            else
            {
                // we dont wanna lose cur hence creating new one
                TreeNode* prev = cur->left;
                // traverse right untill it is either null or points to itself;
                while(prev -> right && prev-> right != cur)
                {
                    prev = prev -> right;
                }
                // case I if right becomes null
                if(prev -> right == NULL)
                {
                    prev -> right = cur;
                    // now move cur to left
                    cur  = cur-> left;
                }
                else
                {
                    // case II it is already pointing to someone
                    // make it null
                    prev-> right = NULL;
                    inorder.push_back(cur->val);
                    cur = cur-> right;
                }
            }

        }
        // TC - O(N) + del(N) ~ O(N)
        // SC - O(1)
        return inorder;
    }
};