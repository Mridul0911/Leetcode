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
    TreeNode* buildTree(TreeNode *root,TreeNode* now,int val)
    {
        TreeNode *p1=now->left;
        TreeNode *p2=now->right;
        now->right=new TreeNode(val);
        now->left=new TreeNode(val);
        now->left->left=p1;
        now->right->right=p2;
        return root;
        
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) 
    {
        if(root==NULL)
        {
            return NULL;
        }
        if(depth==1)
        {
        TreeNode* node=new TreeNode(val);
        node->left=root;
        return node;
        }
        
        queue<TreeNode *> q;
        q.push(root);
        int depthNow=1;
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                if(depthNow==depth-1)
                {
                    if(i==n-1)
                    {
                        return buildTree(root,q.front(),val);
                    }

                    buildTree(root,q.front(),val);
                }
                
                TreeNode *temp=q.front();
                q.pop();
                if(temp->left!=NULL)
                {
                    q.push(temp->left);
                }
                if(temp->right!=NULL)
                {
                    q.push(temp->right);
                }
            }
            depthNow++;
        }
        return NULL;
        
        
        
        
    }
};