class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int k) {
        for(int i=1;i<nums.size();i++)
        {
            nums[i]=nums[i]^nums[i-1];
        }
        int n=nums.size();
        for(int i=n-1;i>=0;i--)
        {
            int gg=(pow(2,k)-1);
            nums[i]=nums[i]^gg;
        }
        reverse(nums.begin(),nums.end());
        return nums;
    }
};