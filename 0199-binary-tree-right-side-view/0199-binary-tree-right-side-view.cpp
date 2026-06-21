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
    void solve(vector<int>& ans, int level, TreeNode* root) {
        if(!root) return;
        if(ans.size() == level) {
            ans.push_back(root->val);
        }

        if(root->right) solve(ans, level+1, root->right);
        if(root->left) solve(ans, level+1, root->left);
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(ans, 0, root);
        return ans;
    }
};