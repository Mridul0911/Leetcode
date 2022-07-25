class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
    int start=0;
        vector<int> ans(2,-1);
        int end=nums.size()-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(target==nums[mid])
            {
                ans[0]=mid;
                end=mid-1;
            }
            else if(target<nums[mid])
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        if(ans[0]==-1)
        {
            return ans; 
        }
        start=0;
        end=nums.size()-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(target==nums[mid])
            {
                ans[1]=mid;
                start=mid+1;
            }
            else if(target<nums[mid])
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
    
    
    
    return ans;
    }
};