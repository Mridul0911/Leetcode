class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        queue<pair<pair<int,int>,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>vis(n,vector<vector<int>>(m,vector<int>(k+1,0)));
        q.push({{0,0},k});
            int ans=0;
             vector<vector<int> > dir{{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty())
        {
            int size=q.size();
             while(size--)
            {
                pair<pair<int,int>,int>p=q.front();
                q.pop();
                int x=p.first.first;
                int y=p.first.second;
                int z=p.second;
                 
               if(x==n-1&&y==m-1)
               {
                   return ans;
               }
                   
                for(int i=0;i<4;i++ )
                {
                    int u=x+dir[i][0];
                    int v=y+dir[i][1];
                    if(u>=0&&u<n&&v>=0&&v<m&&vis[u][v][z]==0)
                    {
                        if(grid[u][v]==0)
                        {
                            q.push({{u,v},z});
                             vis[u][v][z]=1;
                        }
                        else if(grid[u][v]==1&&z>0)
                        {
                            q.push({{u,v},z-1});
                            vis[u][v][z]=1;
                        }
                    }
                     
                }
                 
            }
            ans++;
        }
        
        return -1;
    }
};