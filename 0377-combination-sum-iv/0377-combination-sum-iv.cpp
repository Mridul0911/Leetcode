class Solution {
public:
    int find(vector<int> &nums,int target,vector<int> &dp)
    {
        if(target==0)
        {
            return 1;
        }
        if(target<0)
        {
            return 0;
        }
        if(dp[target]!=-1)
        {
            return dp[target];
        }
        int ans=0;
        for(int it:nums)
        {
            ans+=find(nums,target-it,dp);
        }
        return dp[target]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> dp(target+1,-1);
        return find(nums,target,dp);
    }
};