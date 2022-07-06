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
           if(sum%2!=0)
           {
                   return false;
           }
            else
            {
                 //   return isSubset(nums,nums.size(),sum/2,dp);
                vector<vector<bool>> dp(nums.size(),vector<bool>((sum/2)+1,false)); 
                    for(int i=0;i<n;i++)
                    {
                            dp[i][0]=true;
                    }
                    if(nums[0]<=sum/2)
                    {
                            dp[0][nums[0]]=true;
                    }
                    for(int index=1;index<n;index++)
                    {
                            for(int target=1;target<=(sum/2);target++)
                            {
                                    bool nottake=dp[index-1][target];
                                    bool take=false;
                                    if(nums[index]<=target)
                                    {
                                            take=dp[index-1][target-nums[index]];
                                    }
                                    dp[index][target]=take || nottake;
                            }
                    }
                    
                    return dp[n-1][sum/2];
                    
                    
            }
    }
};