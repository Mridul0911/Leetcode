class Solution {
public:
     
int wiggleMaxLength(vector<int>& nums) {
   int one=1;
        int two=1;
        for(int i=1;i<nums.size();i++)
        {
                if(nums[i]>nums[i-1]) two=one+1;
                if(nums[i]<nums[i-1]) one=two+1;
        }
        return max(two,one);
}
};