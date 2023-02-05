class Solution {
public:
        // int find(int ind,vector<int> &nums,vector<int> &dp,int mid)
        // {
        //         if(ind>=nums.size())
        //         {
        //                 return 0;
        //         }
        //         if(dp[ind]!=-1)
        //         {
        //                 return dp[ind];
        //         }
        //         int take=0;
        //         if(nums[ind]<=mid)
        //         {
        //                 take=1+find(ind+2,nums,dp,mid);
        //         }
        //         int nottake=find(ind+1,nums,dp,mid);
        //         return dp[ind]=max(take,nottake);
        // }
    int minCapability(vector<int>& nums, int k) {
       int left=1;
          int right=1e9;
          int n=nums.size();
        while(left<right){
            int mid=(left+right)/2;
                int take = 0;
            for(int i=0;i<n;i++)
                if(nums[i]<=mid) {
                    take+=1;
                    i++;
                }
            if(take>=k)
                right=mid;
            else
                left=mid+1;
        }
        return left;
    }
};