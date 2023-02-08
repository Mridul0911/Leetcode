class Solution {
public:
        int f(int idx,int n,vector<int>&dp,vector<int> &arr)
  {
      if(idx>=n-1)return 0;
      if(arr[idx]==0)return 1e8;
      if(dp[idx]!=-1)return dp[idx];
      int res=1e8;
      for(int i=1;i<=arr[idx];i++)
      {
          res=min(res,1+f(idx+i,n,dp,arr));
      }
      return dp[idx]=res;
  }
    int jump(vector<int>& nums) {
            int n=nums.size();
        vector<int>dp(n+1,-1);
        int ans=f(0,n,dp,nums);
        return ans;
    }
};