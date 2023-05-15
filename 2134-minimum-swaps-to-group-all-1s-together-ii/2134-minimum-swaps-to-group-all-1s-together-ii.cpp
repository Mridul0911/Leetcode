class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ones=0;
        for(auto it:nums)
        {
            if(it==1)
            {
                ones++;
            } 
        }
        int res=nums.size();
        int j=0;
        int i=0;
        int count=0;
        int n=nums.size();
        while(i<n)
        {
            while(j-i<ones)
            {
                count+=nums[j++ % n];
            }
            res=min(res,ones-count);
            count-=nums[i];
            i++;
        }
        return res;
    }
};