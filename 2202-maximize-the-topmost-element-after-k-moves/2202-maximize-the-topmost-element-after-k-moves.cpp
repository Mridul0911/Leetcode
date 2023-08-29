class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(nums.size()==1 && k%2)
        {
            return -1;
        }
        if(k<2)
        {
            return nums[k];
        }
        if(k>nums.size())
        {
            int maxi=*max_element(nums.begin(),nums.end());
            return maxi;
        }
        int maxi=INT_MIN;
        for(int i=0;i<k-1;i++)
        {
            maxi=max(maxi,nums[i]);
        }
        return max(maxi,nums[k]);
    }
};