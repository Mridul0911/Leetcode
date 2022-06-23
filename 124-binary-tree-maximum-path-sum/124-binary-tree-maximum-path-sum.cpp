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
        int maximumpath(TreeNode *root,int &res)
        {
                if(root==NULL) return 0;
                int lh=max(0,maximumpath(root->left,res));
                int rh=max(0,maximumpath(root->right,res));
                res=max(res,lh+rh+root->val);
                return root->val+max(lh,rh);
        }
        
        
    int maxPathSum(TreeNode* root) {
            int res=INT_MIN;
        maximumpath(root,res);
            return res;
     }
};