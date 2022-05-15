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
    int deepestLeavesSum(TreeNode* root) 
    {
        ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
       queue<TreeNode *> q;
        q.push(root);
        vector<int> ans;
        while(!q.empty())
        {
            int n=q.size();
            int sum=0;
            for(int i=0;i<n;i++)
            {
                TreeNode *temp=q.front();
                q.pop();
                sum+=temp->val;
                if(temp->left!=NULL)
                {
                    q.push(temp->left);
                }
                if(temp->right!=NULL)
                {
                    q.push(temp->right);
                }
                
            }
            ans.push_back(sum);
        } 
        return ans[ans.size()-1];
            
        
    }
};