class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> mp,end;
            for(auto it:nums)
            {
                    mp[it]++;
            }
            for(int i=0;i<nums.size();i++)
            {
                    if(mp[nums[i]]==0) continue;
                    mp[nums[i]]--;
                    if(end[nums[i]-1]>0)
                    {
                            end[nums[i]-1]--;
                            end[nums[i]]++;
                    }
                    else if(mp[nums[i]+1]>0 && mp[nums[i]+2]>0)
                    {
                            mp[nums[i]+1]--;
                            mp[nums[i]+2]--;
                            end[nums[i]+2]++;
                    }
                    else
                    {
                                        return false;
                    }
            }
            return true;
    }
};