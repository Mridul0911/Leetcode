class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
         int n=prices.size();
            int cap=0;
            vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
            
            vector<vector<int>> ahead(2,vector<int>(k+1,0));
            vector<vector<int>> curr(2,vector<int>(k+1,0));
            for(int index=n-1;index>=0;index--)
            {
                    for(int buy=0;buy<=1;buy++)
                    {
                            for(int cap=k-1;cap>=0;cap--)
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