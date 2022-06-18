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
    TreeNode* deleteNode(TreeNode* root, int num) 
    {
        TreeNode *t,*j,*e,*f;
            t=root;
            while(t!=NULL)
            {
                    if(num==t->val)break;
                    j=t;
                    if(num<t->val) t=t->left;
                    else t=t->right;
            }
            if(t==NULL) return root;
            //case of leaf node
           
            //case of leaf node
if(t->left==NULL && t->right==NULL)
{
if(t==root) root=NULL;
else if(j->left==t) j->left=NULL;
else j->right=NULL;
delete t;
return root;
}
            //case of successor
            if(t->right!=NULL)
            {
                for(e=t->right;e->left!=NULL;e=e->left) f=e;
                if(t->right==e)
                {
                        e->left=t->left;
                }
                else
                {
                        f->left=e->right;
                        e->left=t->left;
                        e->right=t->right;
                }
                if(root==t) root=e;//root node
                else if(j->left==t) j->left=e;
                else j->right=e;
             }
            //case of predeccessor
             
            else
            {
                for(e=t->left;e->right!=NULL;e=e->right) f=e;
                if(t->left==e)
                {
                        e->right=t->right;
                }
                else
                {
                        f->right=e->left;
                        e->left=t->left;
                        e->right=t->right;
                }
                if(root==t) root=e;
                else if(j->left==t) j->left=e;
                else j->right=e;
                }
                return root;
            
            
    }
};