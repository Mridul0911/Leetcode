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
      void dfs(TreeNode *root,TreeNode* &prev,int &ans)
      {
              if(root==NULL)
              {
                      return;
              }
                      dfs(root->left,prev,ans);
              if(prev!=NULL)
              {
              ans=min(ans,abs(root->val-prev->val));
              }
              prev=root;
              dfs(root->right,prev,ans);
      }
    int minDiffInBST(TreeNode* root) {
            TreeNode *prev=NULL;
            int ans=INT_MAX;
            dfs(root,prev,ans);
            return ans;
    }
};