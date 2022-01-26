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
    void inorder(TreeNode *root,vector<int> &ans1)
    {
        if(root==NULL) return;
        inorder(root->left,ans1);
        ans1.push_back(root->val);
        inorder(root->right,ans1);
        
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
       vector<int> ans1;
       vector<int> ans2;
        
        inorder(root1,ans1);
        inorder(root2,ans2);
        for(int i=0;i<ans2.size();i++)
        {
            ans1.push_back(ans2[i]);
        }
        sort(ans1.begin(),ans1.end());
        return ans1;
        
    }
};