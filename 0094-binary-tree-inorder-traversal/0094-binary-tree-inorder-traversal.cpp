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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        if(!root) return ans;

        while(true) {
            if(root){
                st.push(root);
                root = root->left;
            }
            else {
                if(st.empty()==true) {
                    break;
                }
                auto curr = st.top();
                st.pop();
                ans.push_back(curr->val);
                root = curr->right;
            }
        }

        return ans;
    }
};