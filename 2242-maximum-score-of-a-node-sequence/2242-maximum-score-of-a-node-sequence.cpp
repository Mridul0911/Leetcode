class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        set<pair<int,int>> inp[scores.size()];
            for(auto it:edges)
            {
                    int src=it[0];
                    int des=it[1];
                    inp[src].insert({scores[des],des});
                    inp[des].insert({scores[src],src});
                    if(inp[src].size()>3) inp[src].erase(inp[src].begin());
                    if(inp[des].size()>3) inp[des].erase(inp[des].begin());
            }
            int ans=-1;
            for(auto it:edges)
            {
                   int cnt=scores[it[0]] +scores[it[1]];
                    for(auto node1:inp[it[0]]){
                            for(auto node2:inp[it[1]]){
                               if (node1.second!=it[0] && node1.second!=it[1] && node2.second != it[0] && node2.second != it[1] && node2.second != node1.second)
                        ans = max(ans,cnt+node1.first+node2.first);                  
                            }
                    }
            }
           return ans; 
    }  
};     