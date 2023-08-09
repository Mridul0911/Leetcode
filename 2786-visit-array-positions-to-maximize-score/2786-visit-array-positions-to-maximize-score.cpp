typedef long long ll;
class Solution {
public:
    ll find(vector<int> &nums,ll x,ll ind,ll gg,vector<vector<ll>> &dp)
    {
        if(ind>=nums.size())
        {
            return 0;
        }
        if(dp[ind][gg]!=-1)
        {
            return dp[ind][gg];
        }
        ll skip=find(nums,x,ind+1,gg,dp);
        ll pick=nums[ind]+find(nums,x,ind+1,nums[ind]&1,dp);
        if((nums[ind]&1)!=gg)pick-=x;
        return dp[ind][gg]=max(pick,skip);
    }
    long long maxScore(vector<int>& nums, int x) {
        vector<vector<ll>> dp(nums.size(),vector<ll>(2,-1));
        return nums[0]+find(nums,x,1,nums[0]&1,dp);
    }
};