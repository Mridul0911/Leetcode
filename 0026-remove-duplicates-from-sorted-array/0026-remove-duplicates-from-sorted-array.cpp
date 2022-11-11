class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
     int n=nums.size();   
        if(n==0)
        {
          return 0;  
        }
        int s=0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]!=nums[i+1])
            {
                nums[s++]=nums[i];
            }
        }
        nums[s]=nums[n-1];
        return s+1;
    }
};