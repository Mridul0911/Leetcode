class Solution {
public:
    int dp[2001][51][51];
    int mod=1e9+7;
    int find(int i,vector<int> &nums,int x,int y)
    {
        if(i>=nums.size())
        {
            return 1;
        }
        if(dp[i][x][y]!=-1)
        {
            return dp[i][x][y];
        }
        long long ans=0;
        for(int j=x;j<=nums[i];j++)
        {
            if(nums[i]-j<=y)
            {
                ans=(ans%mod+find(i+1,nums,j,nums[i]-j)%mod)%mod;
            }
        }
        return dp[i][x][y]=ans%mod;
    }
    int countOfPairs(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return find(0,nums,0,nums[0]);
    }
};