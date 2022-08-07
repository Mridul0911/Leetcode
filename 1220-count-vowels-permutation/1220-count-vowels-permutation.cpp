class Solution {
public:
        int mod=1e9+7;
        int find(int index,int n,int prev,vector<vector<int>> &dp)
        {
                if(index>n)
                {
                        return 0;
                }
                if(index==n)
                {
                        return 1;
                }
                if(dp[index][prev]!=-1)
                {
                        return dp[index][prev];
                }
                int ans=0;
                if(prev==6)
                {
                        ans=(ans%mod+find(index+1,n,1,dp)%mod)%mod;
                        ans=(ans%mod+find(index+1,n,2,dp)%mod)%mod;
                        ans=(ans%mod+find(index+1,n,3,dp)%mod)%mod;
                        ans=(ans%mod+find(index+1,n,4,dp)%mod)%mod;
                        ans=(ans%mod+find(index+1,n,5,dp)%mod)%mod;
                }
                else if(prev==1)
                {
                        ans=(ans%mod+find(index+1,n,2,dp)%mod)%mod;
                        
                }
                else if(prev==2)
                {
                        ans=(ans%mod+find(index+1,n,1,dp)%mod)%mod;
                        ans=(ans%mod+find(index+1,n,3,dp)%mod)%mod;
                }
                else if(prev==3)
                {
                        ans=(ans%mod+find(index+1,n,1,dp)%mod)%mod;
                        ans=(ans%mod+find(index+1,n,2,dp)%mod)%mod;
                        ans=(ans%mod+find(index+1,n,4,dp)%mod)%mod;
                        ans=(ans%mod+find(index+1,n,5,dp)%mod)%mod;
                }
                else if(prev==4)
                {
                        ans=(ans%mod+find(index+1,n,3,dp)%mod)%mod;
                        ans=(ans%mod+find(index+1,n,5,dp)%mod)%mod;
                }
                else if(prev==5)
                {
                        ans=(ans%mod+find(index+1,n,1,dp)%mod)%mod;
                }
                return dp[index][prev]=ans%mod;
        }
    int countVowelPermutation(int n){
        int ans=0;
            vector<vector<int>> dp(n+1,vector<int>(7,-1));
           int x=find(0,n,6,dp)%mod;
            return x;
    }
};