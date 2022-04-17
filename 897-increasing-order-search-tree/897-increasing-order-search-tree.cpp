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
    void find(TreeNode *root,vector<int> &ans)
    {
        if(root==NULL) return;
        find(root->left,ans);
        ans.push_back(root->val);
        find(root->right,ans);
        
    }
    TreeNode* build(vector<int> j)
    {
        TreeNode* node=new TreeNode(j[0]);
        TreeNode* curr=node;
        for(int i=0;i<j.size();i++)
        {
            curr->right=new TreeNode(j[i]);
            curr=curr->right;
        }
        return node->right;
    }
    
    TreeNode* increasingBST(TreeNode* root) 
    {
        vector<int> ans;
      find(root,ans);    
        return build(ans);
    }
};