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
    TreeNode* helper(vector<int>&v, int l, int h)
     {
        if(l>h)
            return NULL;
        int mid=l+(h-l)/2;
        TreeNode* node=new TreeNode(v[mid]);
        node->left= helper(v, l, mid-1);
        node->right=helper(v, mid+1, h);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        int n=nums.size();
        return helper(nums,0,n-1);
    }
};