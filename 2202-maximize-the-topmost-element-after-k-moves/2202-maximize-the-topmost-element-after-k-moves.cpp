class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
            int n=nums.size();
            if(n==1 && k%2==1) return -1;
        if(k>n)
        {
                return *max_element(nums.begin(),nums.end());
        }
            int maxi=INT_MIN;
            for(int i=0;i<k-1;i++)
            {
                    maxi=max(maxi,nums[i]);
            }
            return max(maxi,nums[k]);
    }
};