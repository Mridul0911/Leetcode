class Solution {
public:
        int solve(int src,vector<vector<int>> &adj,vector<bool> &vis,vector<bool> &hasApple)
        {
                vis[src]=true;
                int cost=0;
                for(auto it:adj[src])
                {
                        if(vis[it]==false)
                        {
                                cost+=solve(it,adj,vis,hasApple);
                        }
                }
                if(hasApple[src]!=false || cost>0)
                {
                        cost+=2;
                }
                return cost;
        }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
            vector<bool> vis(n);
            for(auto it:edges)
            {
                    adj[it[0]].push_back(it[1]);
                    adj[it[1]].push_back(it[0]);
            }
            int ans=solve(0,adj,vis,hasApple);
            if(ans>0)
            {
                    return ans-2;
            }
            else
            {
                    return 0;
            }
    }
};