class Solution {
public:
        int find(int ind,vector<int> &nums,vector<int> &dp)
        {
                if(ind==0)
                {
                        return nums[0];
                }
                if(ind<0)
                {
                        return 0;
                }
                if(dp[ind]!=-1)
                {
                        return dp[ind];
                }
                int pick=find(ind-2,nums,dp)+nums[ind];
                int not_pick=find(ind-1,nums,dp)+0;
                return dp[ind]=max(pick,not_pick);
        }
    int rob(vector<int>& nums) {
            vector<int> dp(nums.size(),-1);
            int ans=0;
         ans=find(nums.size()-1,nums,dp);
            return ans;
    }
};