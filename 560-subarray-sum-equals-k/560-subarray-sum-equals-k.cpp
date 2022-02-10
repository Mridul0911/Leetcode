class Solution {
public:
     int subarraySum(vector<int>& nums, int k) {
       map<int,int> m={{0, 1}};
        int count=0;
        int sum=0;
        for(auto i:nums)
        {
            sum+=i;
            count+=m[sum-k];
            m[sum]++;
        }
        return count;
      }
};