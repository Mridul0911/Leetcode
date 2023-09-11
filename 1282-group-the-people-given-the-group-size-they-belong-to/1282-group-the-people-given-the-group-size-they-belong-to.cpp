class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gg) {
        vector<vector<int>> ans;
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<gg.size();i++)
        {
            int groupSize=gg[i];
            if(mp.count(groupSize)>0)
            {
                mp[groupSize].push_back(i);
            }
            else
            {
                mp[groupSize]=vector<int>{i};
            }
            if(mp[groupSize].size()==groupSize)
            {
                ans.push_back(mp[groupSize]);
                mp.erase(groupSize);
            }
        }
        return ans;
    }
};