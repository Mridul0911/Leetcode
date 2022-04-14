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
    TreeNode* searchBST(TreeNode* root, int val) 
    {
       TreeNode *ans=NULL;
            TreeNode *start=root;
            while(start!=NULL)
            {
                    if(start->val==val)
                    {
                            ans=start;
                            break;
                    }
                    else if(start->val>val)
                    {
                            start=start->left;
                    }
                    else
                    {
                            start=start->right;
                    }
            }
            return ans;
                    
            
            
    }
};