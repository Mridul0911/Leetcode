class Solution {
public:
        int find(int index,int buy,int n,vector<int> &prices,int cap,vector<vector<vector<int>>> &dp)
        {
                if(index==n || cap==2)
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
                return dp[index][buy][cap]=max((prices[index]+find(index+1,1,n,prices,cap+1,dp)),find(index+1,0,n,prices,cap,dp));
                
        }
    int maxProfit(vector<int>& prices) 
    {
            int n=prices.size();
            int cap=0;
            vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
            
            vector<vector<int>> ahead(2,vector<int>(3,0));
            vector<vector<int>> curr(2,vector<int>(3,0));
            
            
            
            for(int index=n-1;index>=0;index--)
            {
                    for(int buy=0;buy<=1;buy++)
                    {
                            for(int cap=1;cap>=0;cap--)
                            {
                                        if(buy)
                                        {
                                                curr[buy][cap]=max((-prices[index]+ahead[0][cap]),ahead[1][cap]);
                                        }
                                        else
                                        {
                                                curr[buy][cap]=max((prices[index]+ahead[1][cap+1]),ahead[0][cap]); 
                                        }
                            }
                            ahead=curr;
                    }
            }
            return curr[1][0];
         }
};