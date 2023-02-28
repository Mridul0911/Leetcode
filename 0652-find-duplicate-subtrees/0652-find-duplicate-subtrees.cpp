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
    unordered_map<string,int> ump;
    vector<TreeNode*> ans;
    string find(TreeNode *root)
    {
        if(root==NULL)
        {
            return "null";
        }
        string s = to_string(root->val) + "," + find(root->left) + "," + find(root->right);
        if(ump[s]==1)
        {
            ans.push_back(root);
        }
        ump[s]++;
        return  s;
        
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        ump.clear();
            find(root);
        
        return ans;
        
        
        
    }
};