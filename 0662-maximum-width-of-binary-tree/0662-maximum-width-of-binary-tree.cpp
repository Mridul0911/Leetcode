class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
        {
             return 0;        
        }
            int ans=0;
            queue<pair<TreeNode*,long long int>> q;
            q.push({root,0});
            while(!q.empty())
            {
                   int size=q.size();
                    int first;
                    int last;
                    int min_n=q.front().second;
                    for(int i=0;i<size;i++)
                    {
                            long long int curr=q.front().second-min_n;
                            TreeNode *node=q.front().first;
                            q.pop();
                            if(i==0)
                            {
                                    first=curr;
                            }
                            if(i==size-1)
                            {
                                    last=curr;
                            }
                            if(node->left)
                            {
                                    q.push({node->left,curr*2+1});
                            }
                            if(node->right)
                            {
                                    q.push({node->right,curr*2+2});
                            }
                   }
                    ans=max(ans,last-first+1);
            }
                 return ans;
    }
    };