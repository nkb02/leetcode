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
    // ITERATIVE USING one STACK
    // left- right - root
    void postorder(TreeNode* cur, vector<int> &ans){
        if (cur == NULL) return ;

      stack < TreeNode * > st;
      while (cur != NULL || !st.empty()) {

        if (cur != NULL) {
          st.push(cur);
          cur = cur -> left;
        } else {
          TreeNode* temp = st.top() -> right;
          if (temp == NULL) {
            temp = st.top();
            st.pop();
            ans.push_back(temp -> val);
            while (!st.empty() && temp == st.top() -> right) {
              temp = st.top();
              st.pop();
              ans.push_back(temp -> val);
            }
          } else cur = temp;
        }
      } 

    } 
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};