class Solution {
public:
        void dfs(int src,vector<vector<int>> &isConnected,vector<int> &vis,int n)
        {
                for(int j=0;j<isConnected.size();j++)
                {
                        if(isConnected[src][j]==1 && vis[j]==0)
                        {
                                vis[j]=1;
                                dfs(j,isConnected,vis,n);
                        }
                }
        }
    int findCircleNum(vector<vector<int>>& isConnected) {
     
             int n=isConnected.size();
           
            vector<int> vis(n,false);
                    
            int count=0;
            for(int i=0;i<n;i++)
            {
                 if(!vis[i])
                 {
                          count++;
                         dfs(i,isConnected,vis,n);
                        
                 }
            }
                return count;
            
            
            
            
            
            
            
    }
};