class Solution {
public:
    int dp[2002][2002];
    int solve(int i,int k,vector<int> &stones,unordered_map<int,int> &mp)
    {
        if(i==stones.size()-1)
        {
            return true;
        }
        if(dp[i][k]!=-1)
        {
            return dp[i][k];
        }
        bool cs1=false;
        bool cs2=false;
        bool cs3=false;
        if(mp.find(stones[i]+k)!=mp.end()) {
            cs1=solve(mp[stones[i]+k],k,stones,mp);
        }
        if(k > 1 && mp.find(stones[i]+k-1)!=mp.end()) {
            cs2=solve(mp[stones[i]+k-1],k-1,stones,mp);
        }
        if(mp.find(stones[i]+k+1)!=mp.end()) {
            cs3=solve(mp[stones[i]+k+1],k+1,stones,mp);
        }
        return dp[i][k]=cs1||cs2||cs3;
    }
    bool canCross(vector<int>& stones) {
        if(stones[1]-stones[0]>1)
        {
            return false;
        }
        unordered_map<int,int> mp;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<stones.size();i++)
        {
            mp[stones[i]]=i;
        }
        return solve(1,1,stones,mp);
    }
};