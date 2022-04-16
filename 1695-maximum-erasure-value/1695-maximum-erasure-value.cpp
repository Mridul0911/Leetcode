class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
         int res = 0;
        int currsum = 0;
            int i = 0;
        int j = 0;
          int m[100001] = {};
            int n=nums.size();
         
            while( j < nums.size())
            {
             if(m[nums[j]])
             { 
                while( m[nums[j]]){
                    currsum -= nums[i];
                    m[nums[i]]--;
                    ++i;
                }
             }
             m[nums[j]]++;
             currsum += nums[j];
             res = max (res, currsum);
             ++j;
           }
        return res;
     }
};