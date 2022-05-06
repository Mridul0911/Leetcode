class Solution {
public:
    int maxProduct(vector<int>& nums) {
      
            int n=nums.size();
            int maxi=nums[0];
            int mini=nums[0];
            int ans=nums[0];
            for(int i=1;i<nums.size();i++)
            {
                    if(nums[i]<0)
                    {
                       int temp=maxi;
                        maxi=mini;
                        mini=temp;
                    }
                   maxi=max(nums[i],nums[i]*maxi);
                   mini=min(nums[i],nums[i]*mini);
                    ans=max(ans,maxi);
            }
            return ans;
    }
};