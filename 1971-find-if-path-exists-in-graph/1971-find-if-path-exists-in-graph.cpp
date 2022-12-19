class Solution {
public:
        void dfs(int start,vector<vector<int>> &graph,vector<bool> &vis)
        {
                vis[start]=true;
                for(auto gg:graph[start])
                {
                        if(!vis[gg])
                        {
                                dfs(gg,graph,vis);
                        }
                }
        }
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        
            vector<vector<int>> graph(n);
            for(auto edge:edges)
            {
                    graph[edge[0]].push_back(edge[1]);
                    graph[edge[1]].push_back(edge[0]);
            }
            vector<bool> vis(n);
            dfs(start,graph,vis);
            return vis[end];
    }
};