class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int low =0, high =  nums.size()-1, ans=-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]<target){
                low = mid+1;
            }
            if(nums[mid]>target){
                high = mid-1;
            }
            if(nums[mid]==target){
                ans = mid;
                    break;
            }
        }
        return ans; 
    }
};