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
    TreeNode* build(int val, map<int, pair<int,int>>& mp) {
        TreeNode* node = new TreeNode(val);

        if(mp.find(val) != mp.end()) {
            if(mp[val].first != 0) {
                node->left = build(mp[val].first, mp);
            }
            else {
                node->left = NULL;
            }
            if(mp[val].second != 0) {
                node->right = build(mp[val].second, mp);
            }
            else {
                node->right = NULL;
            }
        }
        return node;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n = descriptions.size();
        map<int, pair<int, int>> mp;
        map<int, int> child;

        for(auto&it : descriptions) {
            if(it[2]) {
                mp[it[0]].first = it[1];
                child[it[1]] = 1;
            }
            else {
                mp[it[0]].second = it[1];
                child[it[1]] = 1;
            }
        }

        int root_val = 0;
        for(auto& it : descriptions) {
            if(child.find(it[0]) == child.end()) {
                root_val = it[0];
                break;
            }
        }

        return build(root_val, mp);
    }
};