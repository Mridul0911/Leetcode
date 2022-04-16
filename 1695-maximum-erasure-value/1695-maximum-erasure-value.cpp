class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i=0;
         int j=1;
            set<int> s;
            int n=nums.size();
            int sum=nums[0];
            s.insert(nums[0]);
            int maxsum = sum;
            while(i<n-1 && j<n)
            {
                    bool it=s.find(nums[j])!=s.end();
                    if(!it)
                    {
                            sum+=nums[j];
                            maxsum=max(maxsum,sum);
                            s.insert(nums[j]);
                            j++;
                    }
                    else
                    {
                       sum-=nums[i];
                            s.erase(nums[i]);
                            i++;
                    }
            }
            return maxsum;
            
    }
};