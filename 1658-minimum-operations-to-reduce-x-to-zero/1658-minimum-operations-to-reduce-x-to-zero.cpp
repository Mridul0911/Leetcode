class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
      int total=0;
        for(int i=0;i<nums.size();i++)
        {
            total+=nums[i];
        }
        total=total-x;
        if(total==0)
        {
            return nums.size();
        }
        int low=0;
        int cur=0;
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            cur+=nums[i];
            while(total<cur and low<nums.size())
            {
                cur-=nums[low++];
            }
            if(total == cur)
            {
                ans = max(ans,i-low+1);
            }
        }
        return (ans==0)?-1:nums.size()-ans; 
    
        

    }
        
        
};