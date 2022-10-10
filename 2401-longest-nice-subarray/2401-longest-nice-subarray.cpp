class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int i=0;
        int j=0;
        long long int sum=0;
        long long int xor_s=0;
        int n=nums.size();
        int ans=INT_MIN;
        while(j<n)
        {
            sum+=nums[j];
            xor_s=xor_s^nums[j];
            if(xor_s==sum)
            {
                ans=max(ans,j-i+1);
                j++;
                if(j==n) break;
            }
            else
            {
                while(xor_s!=sum)
                {
                    xor_s=xor_s^nums[i];
                    sum-=nums[i];
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};