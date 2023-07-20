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


class BSTIterator {
private:
    stack<TreeNode *> st;
    bool reverse = true;
    // true -> before
    // false -> after
public:
    // constructor  
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    // RETURNS THE NEXT SMALLEST NUMBER
    int next() {
        TreeNode* tmpNode = st.top();
        st.pop();
        if(!reverse)
            pushAll(tmpNode ->right);
        else
            pushAll(tmpNode ->left);
        return tmpNode -> val;
    }
    // RETURNS WHETHER THERE IS NEXT SMALLEST NUMBER
    bool hasNext() {
        return !st.empty();
    }

private:
// PUSHES ALL ELEMENTS IN LEFT IN THE STACK 
    void pushAll(TreeNode* node)
    {
        while(node!= NULL)
        {
            st.push(node);
            if(!reverse)
                node = node -> left;
            else
                node = node->right;
        }
        return;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;

        BSTIterator L(root, false); // next
        BSTIterator R(root, true); // before

        int i = L.next();
        int j = R.next();
        while(i < j)
        {
            if(i + j == k)
                return true;
            else if( i + j < k)
            {
                i = L.next();
            }
            else
                j = R.next();
        }
        return false;
    }
};
