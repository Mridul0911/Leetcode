class Solution{
public:
        int mod=1e9+7;
        bool outOfBoundary(int m,int n,int i,int j)
        {
                if(i>=m || j>=n || i<0 || j<0)
                {
                        return true;
                }
                else
                {
                        return false;
                }
        }
        int find(int m,int n,int i,int j,int maxMove,int curr,vector<vector<vector<int>>> &dp)
        {
                if(outOfBoundary(m,n,i,j) && curr<=maxMove)
                {
                        return 1;
                }
                if(curr>maxMove) return 0;
                if(dp[i][j][curr]!=-1)
                {
                        return dp[i][j][curr];
                }
                int count=0;
                count=(count%mod+find(m,n,i+1,j,maxMove,curr+1,dp)%mod)%mod;
                count=(count%mod+find(m,n,i,j+1,maxMove,curr+1,dp)%mod)%mod;
                count=(count%mod+find(m,n,i-1,j,maxMove,curr+1,dp)%mod)%mod;
                count=(count%mod+find(m,n,i,j-1,maxMove,curr+1,dp)%mod)%mod;
                return dp[i][j][curr]=count;  
        }
    int findPaths(int m, int n, int maxMove, int startRow,int startColumn) {
            vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(maxMove+1,-1)));
            return find(m,n,startRow,startColumn,maxMove,0,dp);
    }
};