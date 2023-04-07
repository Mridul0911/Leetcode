class Solution {
public:
    void dfs(int i,int j,vector<vector<int>> &grid)
    {
        //cout<<"HELLO"<<endl;
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!=1)
        {
            return;
        }
        if(grid[i][j]==1)
        {
            grid[i][j]=0;
            dfs(i+1,j,grid);
            dfs(i,j+1,grid);
            dfs(i,j-1,grid);
            dfs(i-1,j,grid);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        
        for(int i=0;i<row;i++)
        {
                dfs(i,0,grid);
                dfs(i,col-1,grid);
        }
        //cout<<"PASSED"<<endl;
        for(int j=0;j<col;j++)
        {
            dfs(0,j,grid);
            dfs(row-1,j,grid);
        }
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    count++;
                }
            }
        }
        return count;
    }
};