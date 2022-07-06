class Solution {
public:
        bool isSubset(vector<int> &nums,int n,int sum,vector<vector<int>>& dp)
        {
                if(sum==0)
                {
                        return true;
                }
                if(n<=0)
                {
                        return false;
                }
                if(dp[n][sum]!=-1)
                {
                        return dp[n][sum];
                }
                  if(sum<nums[n-1])
                   {
                      return  dp[n][sum]=isSubset(nums,n-1,sum,dp);
                   }
return  dp[n][sum]=(isSubset(nums,n-1,sum-nums[n-1],dp)||isSubset(nums,n-1,sum,dp));         }
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
          for(int i=0;i<nums.size();i++)  
          {
                  sum+=nums[i];
          }
            int n=nums.size();
           vector<vector<int>> dp(nums.size()+2,vector<int>((sum/2)+2,-1)); 
           if(sum%2!=0)
           {
                   return false;
           }
            else
            {
                    return isSubset(nums,nums.size(),sum/2,dp);
            }
    }
};