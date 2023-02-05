class Solution {
public:
        int find(int ind,vector<int> &nums,vector<int> &dp,int mid)
        {
                if(ind>=nums.size())
                {
                        return 0;
                }
                if(dp[ind]!=-1)
                {
                        return dp[ind];
                }
                int take=0;
                if(nums[ind]<=mid)
                {
                        take=1+find(ind+2,nums,dp,mid);
                }
                int nottake=find(ind+1,nums,dp,mid);
                return dp[ind]=max(take,nottake);
        }
    int minCapability(vector<int>& nums, int k) {
       int n=nums.size();
            int low=0;
            int high=*max_element(nums.begin(),nums.end());
            int finalans=0;
            while(low<=high)
            {
                    int mid=(low+high)/2;
                    vector<int> dp(n+1,-1);
                    int ans=find(0,nums,dp,mid);
                    // cout<<mid<<" "<<ans<<endl;
                    if(ans>=k)       
                    {
                           high=mid-1;
                           finalans=mid;
                    }
                    else
                    {
                            low=mid+1;
                    }
            } 
            return finalans;
    }
};