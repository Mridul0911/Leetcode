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
    void find(TreeNode *root,int dis,int x,map<int,vector<pair<int, int>>> &m)
    {
        if(root==NULL)
        {
            return;
        }
        m[dis].push_back({x,root->val});
        find(root->left,dis-1,x+1,m);
        find(root->right,dis+1,x+1,m);
     }
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        map<int, vector<pair<int, int>>> m;
        find(root,0,0,m);
        vector<vector<int>> ans;
        // map<int, vector<pair<int, int>>>::iterator it;
        int i=0;
        for(auto &i: m){
            vector<int> temp;
            sort(i.second.begin(), i.second.end());
            for(auto j : i.second){
                temp.push_back(j.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};