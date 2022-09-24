class Solution {
public:
    void find(TreeNode *root,int target,vector<vector<int>> &use,vector<int> &ans)
    {
        if(root==NULL) return;
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
                use.push_back(ans);
            }
        }
        find(root->left,target,use,ans);
        find(root->right,target,use,ans);
        ans.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
    vector<vector<int>> use;
        vector<int> ans;
        find(root,targetSum,use,ans);
        return use;
    }
};