class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int mini=numsDivide[0];
            for(int i=1;i<numsDivide.size();i++)
            {
                   mini=__gcd(numsDivide[i],mini);
            }
            sort(nums.begin(),nums.end());
            for(int i=0;i<nums.size();i++)
            {
                    if(mini%nums[i]==0)
                    {
                            return i;
                    }
           }
            return -1;
    }
};