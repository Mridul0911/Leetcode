class Solution {
public:
    queue<pair<int,int>> q;
    void dfs(vector<vector<int>> &grid,int i,int j)
    {
        if(i>=grid.size() || j>=grid[0].size() || grid[i][j]==0 || grid[i][j]==2 || i<0 || j<0)
        {
            return;
        }
        grid[i][j]=2;
        q.push({i,j});
        dfs(grid,i+1,j);
        dfs(grid,i,j+1);
        dfs(grid,i-1,j);
        dfs(grid,i,j-1);
    }
    int bfs(vector<vector<int>> &grid)
    {
        int ans=INT_MAX;
        int dis=0;
        vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                auto it=q.front();
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int new_x=it.first+dir[i][0];
                    int new_y=it.second+dir[i][1];
                    if(new_x>=0 && new_y>=0 && new_x<grid.size() && new_y<grid[0].size() && grid[new_x][new_y]==1)
                    {
                        ans=min(ans,dis);
                    }
                    if(new_x>=0 && new_y>=0 && new_x<grid.size() && new_y<grid[0].size() && grid[new_x][new_y]==0){
                        q.push({new_x,new_y});
                        grid[new_x][new_y]=2;
                    }
                }
            }
            dis++;
        }
        return ans;    
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int flag=false;
              for(int i=0;i<grid.size();i++)
              {
                  for(int j=0;j<grid[0].size();j++)
                  {
                      if(grid[i][j]==1 && !flag)
                      {
                          dfs(grid,i,j);
                          q.push({i,j});
                          flag=true;
                          break;
                      }
                  }
                  if(flag){
                      break;
                  }
              }
        return bfs(grid);
        
    }
};