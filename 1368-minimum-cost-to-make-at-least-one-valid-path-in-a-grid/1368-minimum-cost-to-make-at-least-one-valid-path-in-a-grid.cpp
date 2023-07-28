class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        vector<pair<int,int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        int n=grid.size();
        int m=grid[0].size();
        using ti=tuple<int,int,int>;
        priority_queue<ti,vector<ti>,greater<>> pq;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        pq.emplace(0,0,0);
        while(!pq.empty())
        {
            auto [cost,x,y]=pq.top();
            pq.pop();
            if(vis[x][y])
            {
                continue;
            }
            vis[x][y]=1;
            if(x==n-1 && y==m-1)
            {
               return cost; 
            }
            for(int i=0;i<4;i++)
            {
                auto &[dx,dy]=dir[i];
                int new_x=x+dx;
                int new_y=y+dy;
                if(new_x>=0 && new_y>=0 && new_x<n && new_y<m && !vis[new_x][new_y])
                {
                    if(i==grid[x][y]-1)
                    {
                        pq.emplace(cost,new_x,new_y);
                    }
                    else
                    {
                        pq.emplace(cost+1,new_x,new_y);
                    }
                }
            }
        }
        return -1;
     }
};