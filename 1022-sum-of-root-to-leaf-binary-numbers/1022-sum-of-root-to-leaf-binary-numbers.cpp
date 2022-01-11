class Solution {
public:
    void findVector(TreeNode *root,vector<int> &j,long long int val,long long int &ans)
    {
        if(root==NULL)
        {
            return;
        }
        val=val*2+root->val;
        if(root->left==NULL && root->right==NULL)
        {
            ans=ans+val;
        }
        findVector(root->left,j,val,ans);
        findVector(root->right,j,val,ans);
    }
    int sumRootToLeaf(TreeNode* root) 
    {
        long long int val=0;
        long long int ans=0;
        vector<int> j;
          findVector(root,j,val,ans);
        return ans;
    }
};