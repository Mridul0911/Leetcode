class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
       sort(nums.begin(),nums.end());
       int i=0;
        int j=0;
        int ans=INT_MIN;
        int n=nums.size();
        while(j<n)
        {
            while(nums[j]-nums[i]>2*k)
            {
                i++;    
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};