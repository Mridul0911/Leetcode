class Solution {
public:
    int find(int curr_index,int prev,vector<pair<int,int>> &inp,vector<vector<int>> &dp)    
    {
            if(curr_index==inp.size())
            {
                    return 0;
            }
            if(dp[curr_index][prev+1]!=-1)
            {
                    return dp[curr_index][prev+1];
            }
            int pick=0;
            int notpick=0;
            if(prev==-1 || inp[curr_index].second>=inp[prev].second)
            {
                    pick=find(curr_index+1,curr_index,inp,dp)+inp[curr_index].second;
            }
            notpick=find(curr_index+1,prev,inp,dp);
            return dp[curr_index][prev+1]=max(pick,notpick);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
             int n=scores.size();
        vector<pair<int,int>> inp;
            for(int i=0;i<scores.size();i++)
            {
                    inp.push_back({ages[i],scores[i]});
            }
            sort(inp.begin(),inp.end());
            vector<vector<int>> dp(n,vector<int>(n,-1));
            return find(0,-1,inp,dp);
    }
};