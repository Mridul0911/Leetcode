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
            vector<int> ahead(2,0);
            vector<int> curr(2,0);
            ahead[0]=0;
            ahead[1]=0;
            for(int index=n-1;index>=0;index--)
            {
                    for(int buy=0;buy<=1;buy++)
                    {
                                int profit=0;
                                if(buy)
                                {
                                        profit=max((-prices[index]-fee+ahead[0]),ahead[1]);
                                }
                                else
                                {
                                        profit=max((prices[index]+ahead[1]),ahead[0]);
                                }
                                curr[buy]=profit;
                    }
                    ahead=curr;
            }
            return curr[1];
    }
};