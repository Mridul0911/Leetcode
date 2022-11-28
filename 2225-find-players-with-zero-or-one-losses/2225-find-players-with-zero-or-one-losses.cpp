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
            vector<vector<int>> answer(2);
            for(auto it:mp)
            {
                    if(it.second.second==0)
                    {
                            answer[0].push_back(it.first);
                    }
                    else if(it.second.second==1)
                    {
                            answer[1].push_back(it.first);
                    }
            }
            return answer;
   }
};