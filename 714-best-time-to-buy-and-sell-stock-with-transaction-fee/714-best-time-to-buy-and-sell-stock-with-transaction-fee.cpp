class Solution {
public:
        // int find(int index,int buy,int n,vector<int> &prices,int fee,vector<vector<int>> &dp)
        // {
        //         if(index==n) return 0;
        //         if(dp[index][buy]!=-1)
        //         {
        //                 return dp[index][buy];
        //         }
        //         int profit=0;
        //         if(buy)
        //         {
        //                 profit=max((-prices[index]-fee+find(index+1,0,n,prices,fee,dp)),find(index+1,1,n,prices,fee,dp));
        //         }
        //         else
        //         {
        //                 profit=max(prices[index]+find(index+1,1,n,prices,fee,dp),find(index+1,0,n,prices,fee,dp));
        //         }
        //         return dp[index][buy]=profit;
        // }
                
    int maxProfit(vector<int>& prices, int fee) {
            int n=prices.size();
            vector<vector<int>> dp(n+1,vector<int>(2,0));
            dp[n][0]=0;
            dp[n][1]=0;
            for(int index=n-1;index>=0;index--)
            {
                    for(int buy=0;buy<=1;buy++)
                    {
                                int profit=0;
                                if(buy)
                                {
                                        profit=max((-prices[index]-fee+dp[index+1][0]),dp[index+1][1]);
                                }
                                else
                                {
                                        profit=max((prices[index]+dp[index+1][1]),dp[index+1][0]);
                                }
                                dp[index][buy]=profit;
                    }
            }
            return dp[0][1];
    }
};