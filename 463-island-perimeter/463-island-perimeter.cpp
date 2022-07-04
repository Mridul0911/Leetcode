class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0;
            int n=grid.size();
            int m=grid[0].size();
            for(int i=0;i<n;i++)
            {
                    for(int j=0;j<m;j++)
                    {
                            if(grid[i][j])
                            {
                                   ans+=4;
                                   if(i<n-1 && grid[i+1][j])ans--; 
                                   if(j<m-1 && grid[i][j+1])ans--; 
                                   if(j  && grid[i][j-1])ans--; 
                                   if(i  && grid[i-1][j])ans--; 
                            }
                    }
            }
            return ans;
   }
};