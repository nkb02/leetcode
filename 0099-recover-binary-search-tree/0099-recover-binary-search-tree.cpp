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
    TreeNode* first; 
    TreeNode* prev;
    TreeNode*  last;
    TreeNode*  middle;
    void inorder(TreeNode* root)
    {
        if(!root) return;

        inorder(root->left);
        if(prev !=NULL && (root-> val < prev -> val))
        {
            //IF FIRST VIOLATION
            if(first == NULL){
                first = prev;
                middle = root;
            }
            // IF 2nd VIOLATION
            else
            {
                last = root;
            }
        }
        // store cur node as prev
        prev = root;
        inorder(root-> right);
    }
public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder( root );
        if(first && last)
            swap(first->val , last->val);
        else if( first && middle)
             swap(first->val , middle->val);
    }
};