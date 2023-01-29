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
        TreeNode *val=NULL;
        void find(TreeNode *root,int x)
        {
                if(root==NULL)
                {
                           return;
                }
                if(root->val==x)
                {
                        val=root;
                        return;
                }
                find(root->left,x);
                find(root->right,x);
        }
        int find_node(TreeNode *root)
        {
                if(root==NULL)
                {
                        return 0;
                }
                int left=find_node(root->left);
                int right=find_node(root->right);
                return left+right+1;
        }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
       find(root,x);
            int leftNode=find_node(val->left);
            int rightNode=find_node(val->right);
            int rem=n-leftNode-rightNode-1;
            if(rem>leftNode+rightNode || rightNode>leftNode+rem || leftNode>rightNode+rem)
            {
                    return true;
            }
            else
            {
                    return false;
            }
    }
};