class Solution {
public:
    int sum;
    void inorder(TreeNode *root)
    {
        if(root==NULL)
        {
            return;
        }
        inorder(root->right);
        sum+=root->val;
        root->val=sum;
        inorder(root->left);
    }
    TreeNode* convertBST(TreeNode* root) 
    {
        if(root==NULL)
        {
            return NULL;
        }
        sum=0;
        inorder(root);
    return root;    
        
        
    }
};