class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        map<int,int> mp;
            for(auto it:nums)
            {
                    mp[it]++;
            }
            vector<int> ans;
            for(auto it:nums)
            {
                    if(mp.find(it+1)==mp.end() && mp.find(it-1)==mp.end() && mp[it]==1)
                    {
                            ans.push_back(it);
                    }
            }
            return ans;
    }
};