class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(p==NULL or q==NULL)                         //any one of them is null then check both are null or not if yes then return yes
            return (p==q);                             //otherwise return false
        
        return (p->val == q->val)                      //check ecah and every time if value is not same at any point of time then 
            && isSameTree(p->left, q->left)            //return false otherwise return true
            && isSameTree(p->right, q->right);
    }
};