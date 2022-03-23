class Solution {
public:
        void dfs(int src,vector<vector<int>> &adj,vector<int> &vis)
        {
                
                vis[src]=1;
                for(auto gg:adj[src])
                {
                        if(!vis[gg])
                        {
                                dfs(gg,adj,vis);
                        }
                }
        }
    int makeConnected(int n, vector<vector<int>>& connections) {
        
            if(connections.size()<n-1)
            {
                    return -1;
            }
            
            
            vector<vector<int>> adj(n);
            for(auto i:connections)
            {
                    adj[i[0]].push_back(i[1]);
                    adj[i[1]].push_back(i[0]);
            }
            int ans=0;
            vector<int> vis(n,0);
            for(int i=0;i<n;i++)
            {
                    if(!vis[i])
                    {
                            dfs(i,adj,vis);
                                    ans++;
                    }
            }
            return ans-1;
    }
};