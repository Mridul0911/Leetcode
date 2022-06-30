class Solution {
public:
        int lis(int prev,int curr,vector<int>& arr,vector<vector<int>> &dp)
    {
        if(curr==arr.size())
        {
            return 0;
        }
            if(dp[curr][prev+1]!=-1)
            {
                    return dp[curr][prev+1];
            }
        int first=0;
        if(prev==-1 || arr[prev]<arr[curr])
        {
            first=1+lis(curr,curr+1,arr,dp);
        }
        int sec=lis(prev,curr+1,arr,dp);
        return dp[curr][prev+1]=max(first,sec);
    }
   int lengthOfLIS(vector<int>& nums) {
           int n=nums.size();
       vector<int> dp(n,1);
           int maxi=1;
           for(int i=0;i<n;i++)
           {
                   for(int prev=0;prev<i;prev++)
                   {
                           if(nums[prev]<nums[i])
                           {
                                   dp[i]=max(dp[i],1+dp[prev]);
                           }
                   }
                   maxi=max(maxi,dp[i]);
           }
        return maxi;
   }
};