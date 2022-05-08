class Solution {
public:
    int maxProfit(vector<int>& prices) {
       vector<int> right_max(prices.size(),0);
            right_max[prices.size()-1]=prices[prices.size()-1];
            for(int i=prices.size()-2;i>=0;i--)
            {
                    right_max[i]=max(right_max[i+1],prices[i]);
            }
            int ans=-1e9;
            for(int i=0;i<prices.size();i++)
            {
                    ans=max(ans,right_max[i]-prices[i]);
            }
            if(ans==-1e9) return 0;
            return ans;
            
    }
};