class Solution {
public:
    int find(vector<int> &prices,int idx,int cap,int buy,int n,vector<vector<vector<int>>> &dp)
    {
        if(idx==n || cap==0)
        {
            return 0;
        }
        if(dp[idx][buy][cap]!=-1)
        {
            return dp[idx][buy][cap];
        }
        if(buy)
        {
            return dp[idx][buy][cap]=max((-prices[idx]+find(prices,idx+1,cap,0,n,dp)),find(prices,idx+1,cap,1,n,dp));
        }
        return dp[idx][buy][cap]=max((prices[idx]+find(prices,idx+1,cap-1,1,n,dp)),find(prices,idx+1,cap,0,n,dp));
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
       return find(prices,0,2,1,n,dp);
    }
};