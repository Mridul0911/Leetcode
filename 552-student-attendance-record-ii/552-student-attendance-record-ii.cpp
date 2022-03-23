class Solution {
public:
        int mod=1e9+7;
        long long dp[100001][2][3];
    long long solve(int index,int a,int l,int n)
    {
        if(a>1 || l>2)
        {
            return 0;
        }
            if(index==n)
        {
            return 1;
        }
            if(dp[index][a][l]!=-1)
            {
                    return dp[index][a][l];
            }
        long long ans=0;
       ans=(ans%mod+solve(index+1, a, 0,n)%mod + solve(index+1, a, l+1,n)%mod + solve(index+1, a+1, 0,n)%mod)%mod;
        return dp[index][a][l]=ans;
    }
    
    int checkRecord(int n) {
           // int dp[100001][2][3];
            // vector<vector<vector<long long>>> dp(1000005,vector<vector<long long>>(2,vector<long long>(3,-1)));
            memset(dp,-1,sizeof(dp));
      return solve(0,0,0,n);
           
     }
};

