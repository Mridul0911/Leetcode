class Solution {
public:
        void dfs(vector<vector<int>> &rooms,vector<bool> &vis,int source)
        {
                vis[source]=true;
                for(auto it:rooms[source])
                {
                        if(!vis[it])
                        {
                                dfs(rooms,vis,it);
                        }
                }
        }
                
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> vis(rooms.size(),false);
           dfs(rooms,vis,0);
            
            
            for(int i=0;i<vis.size();i++)
            {
                    if(!vis[i])
                    return false;
            }
            return true;
    }
};