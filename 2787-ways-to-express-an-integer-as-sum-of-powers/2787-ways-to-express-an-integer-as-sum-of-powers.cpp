class Solution {
public:
    int mod=1e9+7;
    int find(int n,int x,int i,vector<vector<int>> &dp)
    {
        if(n==0)
        {
            return 1;
        }
        if(i>n)
        {
            return 0;
        }
        if(n<0)
        {
            return 0;
        }
        if(dp[n][i]!=-1)
        {
            return dp[n][i];
        }
        if(pow(i,x)<=n)
        {
            return dp[n][i]=(find(n-pow(i,x),x,i+1,dp)%mod + find(n,x,i+1,dp)%mod)%mod;
        }
        else
        {
            return dp[n][i]=(find(n,x,i+1,dp))%mod;
        }
    }
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(301,vector<int>(301,-1));
        return find(n,x,1,dp);
    }
};