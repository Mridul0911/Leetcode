class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long int ans=0;
       int i=0,j=0;
        long long int l=0;
        while(j<nums.size())
        {
            if(nums[j]==0)l++;
            else
            {
                ans=ans+(l*(l+1))/2;
                l=0;
            }
            j++;
        }
      ans=ans+(l*(l+1))/2;
        return ans;
            
    }
};