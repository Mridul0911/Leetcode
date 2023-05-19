class Solution {
public:
   vector<int>vis,col;
    bool dfs(int i,int c,vector<vector<int>> &graph)
    {
            vis[i]=true;
            col[i]=c;
            for(auto gg:graph[i])
            {
                    if(vis[gg]==false && dfs(gg,c^1,graph)==false)
                    {
                            return false;
                    }
                    else
                    {
                            if(col[i]==col[gg])
                            {
                                    return false;
                            }
                    }
            }
            return true;
    }
        
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vis.resize(n);
        col.resize(n);

        for(int i=0;i<n;++i){
            if(vis[i]==0 && dfs(i,0,graph)==false){ 
                return false;
            }
        }
        
        return true;
          }
};