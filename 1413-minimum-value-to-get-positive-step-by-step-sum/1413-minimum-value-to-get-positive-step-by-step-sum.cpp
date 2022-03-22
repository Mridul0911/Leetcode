class Solution {
public:
    int minStartValue(vector<int>& nums) {
       int x = 1;
    for (int i = nums.size() - 1; i >= 0; i--) {
        x = x - nums[i];
        if (x < 1) x = 1;
    }
    return x; 
    }
};