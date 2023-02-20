class Solution {
    public int searchInsert(int[] nums, int target) {
     if(target>nums[nums.length-1])   
     {
         return nums.length;
     }
        int l=0;
        int r=nums.length-1;
        while(l<=r)
        {
        int mid = (l+r)/2;
        if(target > nums[mid])
        {
            l=mid+1;
        }
        else if(target < nums[mid])
        {
            r=mid-1;
        }
        else
        {
        return mid;
        }
        }
       return l;  
    }
}