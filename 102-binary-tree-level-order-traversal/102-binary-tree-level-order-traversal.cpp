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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<int> ans;
        vector<vector<int>> use;
        
        if(root==NULL)
        {
            return use;
        }
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode *temp=q.front();
                q.pop();
                if(temp!=NULL)
                {
                ans.push_back(temp->val);
                }
                if(temp->left!=NULL)
                {
                q.push(temp->left);
                }
                if(temp->right!=NULL)
                {
                q.push(temp->right);
                }
            }
            use.push_back(ans);
            ans.clear();
        }
        return use;
    }
};