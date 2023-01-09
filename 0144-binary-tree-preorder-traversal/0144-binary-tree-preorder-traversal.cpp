class Solution {
public:
    vector<int> help(TreeNode* root,vector<int>& ans)
    {
        if(root==NULL)
            return ans;
        
        ans.push_back(root->val);
        help(root->left,ans);
        help(root->right,ans);
        return ans;
    }
    vector<int> preorderTraversal(TreeNode* root) 
    {
        // preorder = root -> left -> right
         
        vector<int> ans;
        return help(root,ans);
        
        
    }
    
    
};