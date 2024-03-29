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

   static int MOD=1e9+7;
class Solution {
public:
    long long totalTreeSum=0,result=0;
    int Sum(TreeNode* root)             
    {
        if(root==NULL)
            return 0;
        long long sum=Sum(root->left)+Sum(root->right)+root->val;
        result=max(result,sum*(totalTreeSum-sum));
        return sum;
    }
    int maxProduct(TreeNode* root) 
    {
        totalTreeSum=Sum(root);
        Sum(root);
        return result%MOD;
    }
};
