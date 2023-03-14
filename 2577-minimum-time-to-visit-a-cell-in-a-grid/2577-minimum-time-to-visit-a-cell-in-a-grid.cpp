class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
            if(grid[0][1]>1 && grid[1][0]>1)
            {
                    return -1;
            }
        int n=grid.size();
            int m=grid[0].size();
            vector<vector<bool>> vis(n,vector<bool>(m,false));
            priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
            pq.push({grid[0][0],0,0});
            vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            while(!pq.empty())
            {
                  int time=pq.top()[0];
                  int row=pq.top()[1];
                  int col=pq.top()[2];
                  pq.pop();
                  if(row==n-1 && col==m-1)
                  {
                            return time;
                  }
                  if(vis[row][col])  continue;
                  vis[row][col]=true;
                  for(auto it:dirs)
                  {
                            int new_row=row+it[0];
                            int new_col=col+it[1];
                            if(new_row<0 || new_col<0 || new_row>=n || new_col>=m || vis[new_row][new_col])
                            {
                                    continue;
                            }
                            if(grid[new_row][new_col]<=time+1)
                            {
                                    pq.push({time+1,new_row,new_col});
                            }
                            else 
                            {
                                    int diff=grid[new_row][new_col]-time;
                                    if(diff%2==1)
                                    {
                                            pq.push({grid[new_row][new_col],new_row,new_col});
                                    }
                                    else
                                    {
                                            pq.push({grid[new_row][new_col]+1,new_row,new_col});       
                                    }
                            }
                   }
            }
            return -1;
    }
};