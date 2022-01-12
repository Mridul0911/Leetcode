class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       
vector<int> ans(nums.size(),1)            ;
            int prefix=nums[0];
            
            int n=nums.size();
            for(int i=1;i<nums.size();i++)
            {
                    ans[i]=prefix;
                    prefix=prefix*nums[i];
            }
            prefix=nums[n-1];
            for(int i=n-2;i>=0;i--)
            {
                ans[i]=prefix*ans[i];
                    prefix=prefix*nums[i];
            }
            return ans;
          }
};