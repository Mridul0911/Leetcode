class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
            ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
        map<int,pair<int,int>> mp; //wins ,losses
            for(auto it:matches)
            {
                    mp[it[0]].first++;
                    mp[it[1]].second++;
            }
            vector<int> ans1;
            vector<int> ans2;
            for(auto it:mp)
            {
                    if(it.second.second==0)
                    {
                            ans1.push_back(it.first);
                    }
                    else if(it.second.second==1)
                    {
                            ans2.push_back(it.first);
                    }
            }
            vector<vector<int>> finalans;
            finalans.push_back(ans1);
            finalans.push_back(ans2);
            return finalans;
   }
};