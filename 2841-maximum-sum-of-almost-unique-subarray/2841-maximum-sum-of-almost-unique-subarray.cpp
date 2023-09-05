class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        unordered_map<int,int> mp;
        long long sum=0;
        long long maxi=0;
        int i=0;
        int j=0;
        while(j<nums.size())
        {
            mp[nums[j]]++;
            sum+=nums[j];
            if(j-i+1>k)
            {
                mp[nums[i]]--;
                sum-=nums[i];
                if(mp[nums[i]]==0)
                {
                    mp.erase(nums[i]);    
                }
                i++;
            }
            if(j-i+1==k)
            {
                if(mp.size()>=m)
                {
                    maxi=max(sum,maxi);
                }
            }
            j++;
        }
        return maxi;
    }
};