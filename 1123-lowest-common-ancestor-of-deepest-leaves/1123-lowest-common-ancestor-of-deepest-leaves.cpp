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
    int getHeight(TreeNode *root)
    {
        if(root==NULL) return 0;
            int leftheight=getHeight(root->left);
            int rightheight=getHeight(root->right);
            return 1+max(leftheight,rightheight);
    }    
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root==NULL) return NULL;
        int left=getHeight(root->left);
        int right=getHeight(root->right);
        if(left==right)
           {
               return root;
           }
        else if(left>right)
        {
            return lcaDeepestLeaves(root->left);
        }
        else if(left<right)
        {
            return lcaDeepestLeaves(root->right);
        }
        return root;
    }
};