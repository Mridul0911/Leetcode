class Solution 
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
       int n=grid.size();
            int m=grid[0].size();
           vector<vector<int>>grid1=grid;   
          while(k--)
          {
            int n=grid.size();
            int m=grid[0].size();
            for(int i=0;i<grid.size();i++)
            {
                for(int j=0;j<grid[0].size();j++)
                {
                       
                    if(j+1<m)
                    {
                      grid1[i][j+1]=grid[i][j]; 
                    }

                    if(i+1<n)
                    {
                     grid1[i+1][0]=grid[i][m-1];   
                    }
                     
                }
            }
            grid1[0][0]=grid[n-1][m-1];
            grid=grid1;
          } 
           return grid1; 
    }
};