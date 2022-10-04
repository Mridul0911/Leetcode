class Solution {
public:
    void find(TreeNode *root,vector<int> &ans,int &flag,int target)
    {
        if(root==NULL)
        {
            return ;
        }
        ans.push_back(root->val);
        if(root->right==NULL && root->left==NULL)
        {
            int sum=0;
            for(int i=0;i<ans.size();i++)
            {
                sum+=ans[i];
            }
            if(sum==target)
            {
                flag=1;
            }
        }
        find(root->left,ans,flag,target);
        find(root->right,ans,flag,target);
        ans.pop_back();
    }
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        vector<int> ans;
        int flag=0;
        find(root,ans,flag,targetSum);
        if(flag==1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};