class Solution {
public:
       
         int mod=1e9+7; 
        long long check(int i,int j,vector<vector<int>> &grid,int x,vector<vector<int>> &dp,int n,int m)
        {
               if(dp[i][j] != -1) return dp[i][j];
	   long long a = 0, b = 0, c = 0, d = 0;
           if(i != n-1 && grid[i+1][j]>grid[i][j]) a = 1+check(i+1,j,grid,x,dp,n,m);
           if(j != m-1 && grid[i][j+1]>grid[i][j]) b = 1+check(i,j+1,grid,x,dp,n,m);
           if(i && grid[i-1][j]>grid[i][j]) c = 1+check(i-1,j,grid,x,dp,n,m);
           if(j && grid[i][j-1]>grid[i][j]) d = 1+check(i,j-1,grid,x,dp,n,m);
           return dp[i][j]=(a+b+c+d)%mod;      
        }
    int countPaths(vector<vector<int>>& grid) {
      long long  ans=0;
            vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
            int n=grid.size();
            int m=grid[0].size();
            for(int i=0;i<grid.size();i++)
            {
                    for(int j=0;j<grid[i].size();j++)
                    {
                            ans=ans+(1+check(i,j,grid,-1,dp,n,m))%mod;
                            ans%=mod;
                    }
            }
                return (int)ans;
    }
};