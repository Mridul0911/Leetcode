class Solution {
public:
    int solve(int i,int j,vector<vector<int>> &dp)
    {
            if(i==0 && j==0)
            {
                    return 1;
            }
            if(i<0 || j<0)
            {
                    return 0;
            }
            if(dp[i][j]!=-1)
            {
                    return dp[i][j];
            }
            int up=solve(i-1,j,dp);
            int down=solve(i,j-1,dp);
            return dp[i][j]=up+down;
    }
    int uniquePaths(int m, int n) {
       vector<vector<int>> dp(m,vector<int>(n,0));
            dp[0][0]=1;
            for(int i=0;i<m;i++)
            {
                    for(int j=0;j<n;j++)
                    {
                            
                            if(i==0 && j==0) {
                                    dp[0][0]=1;
                                    continue;
                            } 
                            int up=0;
                                    int down=0;
                                    if(i>0) up=dp[i-1][j] ;
                                    if(j>0) down=dp[i][j-1];
                            dp[i][j]=up+down;
                    }
            }
            return dp[m-1][n-1];
            
            
    }
};