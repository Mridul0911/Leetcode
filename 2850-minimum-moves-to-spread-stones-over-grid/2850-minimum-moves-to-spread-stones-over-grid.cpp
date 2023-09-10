class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
             for(int j=0;j<grid[0].size();j++)
             {
                 if(grid[i][j]==0)
                 {
                     count++;
                 }
             }
        }
        if(count==0)
        {
            return 0;
        }
        int ans=INT_MAX;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(grid[i][j]==0)
                {
                    for(int x=0;x<3;x++)
                    {
                        for(int y=0;y<3;y++)
                        {
                            int distance=(abs(x-i)+abs(y-j));
                            if(grid[x][y]>1)
                            {
                                grid[i][j]++;
                                grid[x][y]--;
                                ans=min(ans,distance+minimumMoves(grid));
                                grid[i][j]--;
                                grid[x][y]++;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};