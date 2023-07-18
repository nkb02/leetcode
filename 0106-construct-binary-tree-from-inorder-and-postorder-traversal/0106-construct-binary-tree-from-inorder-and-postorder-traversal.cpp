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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size())
            return NULL;
        int postStart = 0;
        int postEnd = postorder.size() - 1;
        int inStart = 0, inEnd = inorder.size()-1;
        map<int, int> mp;
        for(int i= inStart; i<= inEnd ; i++)
        {
            mp[inorder[i]] = i;
        }
        return constructTree(postorder, postStart, postEnd, inorder, inStart, inEnd, mp);
    }
    TreeNode* constructTree( vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int>& mp){
        if(postStart > postEnd || inStart > inEnd)
            return NULL;
        
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int elem = mp[postorder[postEnd]];
        int nelem = elem - inStart;
        root -> left = constructTree(postorder, postStart, postStart + nelem - 1 , inorder,
         inStart, elem - 1, mp);
        root -> right = constructTree(postorder, postStart + nelem, postEnd-1, inorder,
         elem + 1, inEnd, mp);

        return root; 
    } 
};