class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) 
    {
        sort(coins.begin(),coins.end());
        int res=1;
        for(int i=0;i<coins.size();i++)
        {
            if(res>=coins[i])
            {
                res+=coins[i];
            }
            else
            {
                break;
            }
        }
      return res;    
    }
};