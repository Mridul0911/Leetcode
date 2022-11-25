class Solution {
public:   
        int flag=0;
void dfs(int src,vector<int> &rightChild,vector<int> &leftChild,vector<bool> &vis)
        {
            vis[src]=true;
           if(leftChild[src]!=-1)
           {
                   if(vis[leftChild[src]]==true)
                   {
                     flag=1;
                           return;
                   }
                   else
                   {
                           dfs(leftChild[src],rightChild,leftChild,vis);
                   }
           }
        if(rightChild[src]!=-1)
           {
                   if(vis[rightChild[src]]==true)
                   {
                     flag=1;
                           return;
                   }
                   else
                   {
                           dfs(rightChild[src],rightChild,leftChild,vis);
                   }
           }
           
        }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int root=0;
            vector<int> indeg(n,0);
            for(int i=0;i<n;i++)
            {
                    if(leftChild[i]!=-1)
                    {
                            indeg[leftChild[i]]++;
                    }
                    if(rightChild[i]!=-1)
                    {
                            indeg[rightChild[i]]++;
                    }
            }
            int ans=0;
            for(int i=0;i<n;i++)
            {
                    if(indeg[i]==0)
                    {
                            root=i;
                            ans++;
                    }
            }
            if(ans!=1)
            {
                    return false;
            }
            vector<bool> vis(n,false);
          dfs(root, rightChild, leftChild, vis);  
            for(int i=0;i<n;i++)
            {
                    if(vis[i]==false)
                    {
                            return false;
                    }
            }
            if(flag==1)
            {
                    return false;
            }
            return true;
    }
};