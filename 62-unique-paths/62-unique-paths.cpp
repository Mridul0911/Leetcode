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
      vector<int> prev(n,0);
              vector<int> temp(n,0);
            for(int i=0;i<m;i++)
            {
                    for(int j=0;j<n;j++)
                    {
                            
                            if(i==0 && j==0) {
                                    temp[j]=1;
                                    continue;
                            } 
                            int up=0;
                                    int down=0;
                                    if(i>0) up=prev[j] ;
                                    if(j>0) down=temp[j-1];
                            temp[j]=up+down;
                    }
                    prev=temp;
            }
            return prev[n-1];
         }
};