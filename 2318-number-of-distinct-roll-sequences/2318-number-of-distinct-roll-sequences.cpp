class Solution {
public:
        int mod=1e9+7;
        int find(int n,int prev,int prevkaprev,vector<vector<vector<int>>> &dp)
        {
                if(n==0)
                {
                        return 1;
                }
                if(dp[n][prev][prevkaprev]!=-1)
                {
                        return dp[n][prev][prevkaprev]%mod;
                }
                if(prev==0)
                {
                        int ans=0;
                        for(int i=1;i<=6;i++)
                        {
                                ans=ans+find(n-1,i,prev,dp)%mod;
                                ans=ans%mod;
                        }
                        return dp[n][prev][prevkaprev]=ans%mod;
                }
                else if(prevkaprev==0)
                {
                        int ans=0;
                        for(int i=1;i<=6;i++)
                        {
                                if(__gcd(i,prev)==1 && i!=prev)
                                {
                                        ans=ans+find(n-1,i,prev,dp)%mod;
                                        ans=ans%mod;
                                }
                        }
                        return dp[n][prev][prevkaprev]=ans%mod;
                }
                int ans=0;
                for(int i=1;i<=6;i++)
                {
                       if(__gcd(i,prev)==1 && i!=prev && i!=prevkaprev)
                        {
                                ans=ans+find(n-1,i,prev,dp)%mod;
                                ans=ans%mod;
                        }
                }
                return dp[n][prev][prevkaprev]=ans%mod;
        }
    int distinctSequences(int n) {
       vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(7,vector<int>(7,-1)));
      return find(n,0,0,dp);
    }
};