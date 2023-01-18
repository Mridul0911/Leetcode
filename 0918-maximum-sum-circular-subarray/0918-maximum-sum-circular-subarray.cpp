class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        int end=0; 
        for(int i=0;i<n;i++)
        {
                end=end+nums[i];
                if(maxi<end)
                {
                        maxi=end;
                }
                if(end<0)
                {
                        end=0;
                }
        }
        int mini=INT_MAX;
        int total=0;
        for(int i=0;i<n;i++)
        {
                total+=nums[i];
                end=end+nums[i];
                if(end<mini)
                {
                        mini=end;
                }
                if(end>0)
                {
                        end=0;
                }
        }
        if(maxi>0)
        {
                return max(maxi,total-mini);
        }
        else
        {
                return maxi;
        }
    }
};