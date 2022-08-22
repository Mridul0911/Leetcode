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
        TreeNode *startingEdge=NULL;
        int totalNode;
        void dfs(TreeNode *root,unordered_map<int,TreeNode*> &mp,int start)
        {
               if(root==NULL)
               {
                       return;
               }
                if(root->left) mp[root->left->val]=root;
                if(root->right) mp[root->right->val]=root;
                if(root->val==start) startingEdge=root;
                dfs(root->left,mp,start);
                dfs(root->right,mp,start);
               totalNode++; 
        }
        
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,TreeNode *> mp;
            totalNode=0;
         dfs(root,mp,start);
            queue<TreeNode *> q;
            q.push(startingEdge);
            unordered_set<int> vis;
            int ans=0;
            while(!q.empty())
            {
                    int sz=q.size();
                    while(sz--)
                    {
                          TreeNode *curr=q.front();
                                q.pop();
                            if(vis.count(curr->val)) continue;
                            vis.insert(curr->val);
                            if(vis.size()==totalNode)
                            {
                                    return ans;
                            }
                            if(mp.count(curr->val))
                            {
                                    q.push(mp[curr->val]);
                            }
                            if(curr->left)
                            {
                                    q.push(curr->left);
                            }
                            if(curr->right)
                            {
                                    q.push(curr->right);
                            }
                    }
                    ans++;
            }
            return ans;
        }
};