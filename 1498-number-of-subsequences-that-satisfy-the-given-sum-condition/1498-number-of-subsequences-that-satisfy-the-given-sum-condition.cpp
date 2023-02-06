class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
            int i=0;
            int j=nums.size()-1;
            int ans=0;
            int mod=1e9+7;
            vector<int> power(nums.size(),0);
            power[0]=1;
            for(int i=1;i<nums.size();i++)
            {
                    power[i]=(power[i-1]*2)%mod;
            }
            // for(auto it:power)
            // {
            //         cout<<it<<endl;
            // }
            while(i<=j)
            {
                    if(nums[i]+nums[j]<=target)
                    {
                         ans=(ans%mod)+power[j-i]%mod;
                         i++;
                    }
                    else
                    {
                         j--;
                    }
            }
            return ans%mod;
    }
};