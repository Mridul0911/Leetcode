class Solution {
public:
        int dfs(int i,int j,vector<vector<int>> &grid)
        {
                int ans=0,temp=0;
                if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0)
                {
                        return 0;
                }
                temp=grid[i][j];
                grid[i][j]=0;
                ans=max(ans,dfs(i+1,j,grid));
                ans=max(ans,dfs(i,j+1,grid));
                ans=max(ans,dfs(i-1,j,grid));
                ans=max(ans,dfs(i,j-1,grid));
                grid[i][j]=temp;
                return temp+ans;
        }
     int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
            int m=grid[0].size();
            int ans=0;
            for(int i=0;i<n;i++)
            {
                    for(int j=0;j<m;j++)
                    {
                            if(grid[i][j]>0)
                            ans = max(ans , dfs(i,j,grid));
                    }
            }
             return ans;
    }
};