class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
            multiset<int> ml;
            int j=0;
            int max_size=INT_MIN;
            for(int i=0;i<nums.size();i++)
            {
                    ml.insert(nums[i]);
                    while(*ml.rbegin()-*ml.begin()>limit)
                    {
                            ml.erase(ml.find(nums[j]));
                            j++;
                    }
                    max_size=max(max_size,(int)ml.size());
            }
            return max_size;
        }
};