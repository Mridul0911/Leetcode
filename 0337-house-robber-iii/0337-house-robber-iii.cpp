class Solution {
public:
    unordered_map<TreeNode*,int> mp;
    int rob(TreeNode* root) {
        if(mp.count(root))
        {
            return mp[root];
        }
        if(root==NULL)
        {
            return 0;
        }
        int pick=root->val;
        if(root->left)
        {
            pick+=(rob(root->left->left)+rob(root->left->right));
        }
        if(root->right)
        {
            pick+=(rob(root->right->left)+rob(root->right->right));
        }
        int not_pick=rob(root->left)+rob(root->right);
        return mp[root]=max(pick,not_pick);
    }
};