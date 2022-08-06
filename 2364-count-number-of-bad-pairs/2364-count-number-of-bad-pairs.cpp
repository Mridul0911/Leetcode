class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
            long long n=nums.size();
       map<long long,long long> mp;
            long long int ans=0;
            for(int i=0;i<nums.size();i++)
            {
                    long long int diff=nums[i]-i;
                    if(mp.find(diff)!=mp.end())
                    {
                        ans+=mp[diff]      ;
                            mp[diff]++;
                    }
                    else
                    {
                            mp[diff]=1;
                    }
            }
            long long total=(n*(n-1))/2;
            return total-ans;
    }
};