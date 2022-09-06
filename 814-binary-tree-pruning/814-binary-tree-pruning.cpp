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
    bool isZero(TreeNode *root)
    {
        if(root==NULL) return true;
        if(root->val!=0)
        {
            return false;
        }
        return isZero(root->left)&&isZero(root->right);
    }
    TreeNode* pruneTree(TreeNode* root) 
    {
        if(root==NULL)
        {
            return NULL;
        }
        if(isZero(root))
        {
            return NULL;
        }
        root->left=pruneTree(root->left);
        root->right=pruneTree(root->right);
        return root;
    }
};