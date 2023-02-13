class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long int ans=0;
            for(int i=0;i<nums.size();i++)
            {
                    int x=lower-nums[i];
                    int y=upper-nums[i];
                    auto lower=lower_bound(nums.begin()+i+1,nums.end(),x);
                    auto upper=upper_bound(nums.begin()+i+1,nums.end(),y);
                    ans+=abs(upper-lower);
            }
            return ans;
    }
};