class Solution {
public:
    TreeNode *dfs;
    void inorder(TreeNode *root,TreeNode* target)
    {
        if(root==NULL) return;
        inorder(root->left,target);
        if(root->val==target->val)
        {
            dfs=root;
        }
        inorder(root->right,target);    
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) 
    {
        inorder(cloned,target);
        return dfs;    
    }
};