class Solution {
public:
        int find(int index,int buy,int n,vector<int> &prices,int cap,vector<vector<vector<int>>> &dp)
        {
                if(index==n || cap==0)
                {
                        return 0;
                }
                if(dp[index][buy][cap]!=-1)
                {
                        return dp[index][buy][cap];
                }
                if(buy)
                {
                        return dp[index][buy][cap]=max((-prices[index]+find(index+1,0,n,prices,cap,dp)),find(index+1,1,n,prices,cap,dp));
                }
                return dp[index][buy][cap]=max((prices[index]+find(index+1,1,n,prices,cap-1,dp)),find(index+1,0,n,prices,cap,dp));
                
        }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
            int cap=0;
            vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
           return find(0,1,n,prices,2,dp);
    }
};