class Solution {
public:
    bool isPossible(vector<int>& nums) {
      unordered_map<int,int> mp;
            for(auto it:nums)
            {
                    mp[it]++;
            }
            for(int i=0;i<nums.size();i++)
            {
                    if(mp[nums[i]]==0)
                    {
                            continue;
                    }
                    int freq=mp[nums[i]];
                    int ans=0;
                    int curr=nums[i];
                    while(mp.count(curr) && mp[curr]>=freq)
                    {
                            freq=max(freq,mp[curr]);
                            mp[curr]--;
                            ans++;
                            curr++;
                    }
                    if(ans<3)
                    {
                            return false;
                    }
            }
            return true;
    }
};