class Solution {
public:
    int mod=(int)1e9+7;
    int getMinPeople(int N,int minProfit,int n,vector<int> &profit,vector<int> &group,vector<vector<vector<int>>> &dp){
        if(n==0){
            if(minProfit==0) return 1;
             return 0;
        }
        if(N==0){
            if(minProfit) return 0;
            return 1;
        }
        if(dp[N][minProfit][n]!=-1) 
        {
                return dp[N][minProfit][n];
        }
        int cnt=getMinPeople(N-1,minProfit,n,profit,group,dp);
        if(group[N-1]<=n){
            int x=getMinPeople(N-1,max(0,minProfit-profit[N-1]),n-group[N-1],profit,group,dp);
            cnt=(cnt%mod+x%mod)%mod;
        }
        return dp[N][minProfit][n]=cnt;
 }
   int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int N=group.size();
        vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(minProfit+1,vector<int>(n+1,-1)));
        return (getMinPeople(N,minProfit,n,profit,group,dp)==INT_MAX)?-1:dp[N][minProfit][n];
    }
};