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
    TreeNode *insert(TreeNode *root,int x)
    {
        TreeNode *rootx=NULL;
        if(root==NULL)
        {
            rootx=new TreeNode(x);
            return rootx;
        }
        else
        {
            if(root->val>x)
            {
                root->left=insert(root->left,x);
            }
            if(root->val<x)
            {
                root->right=insert(root->right,x);
            }
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root=NULL;
        for(int i=0;i<preorder.size();i++)
        {
            root=insert(root,preorder[i]);
        }
        return root;
    }
};