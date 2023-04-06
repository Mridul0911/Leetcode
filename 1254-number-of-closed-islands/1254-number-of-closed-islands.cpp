class Solution {
public:
    int dfs(int i,int j,vector<vector<int>> &grid)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
        {
            return false;
        }
        if(grid[i][j]==1)
        {
            return true;
        }
        grid[i][j]=1;
        int d1=dfs(i+1,j,grid);
        int d2=dfs(i,j+1,grid);
        int d3=dfs(i-1,j,grid);
        int d4=dfs(i,j-1,grid);
        return d1&&d2&&d3&&d4;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int res=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==0)
                {
                    if(dfs(i,j,grid))
                    {
                        res++;
                    }
                }
            }
        }
        return res;
    }
};