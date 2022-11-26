class Solution {
public:
        int find(int index,vector<int> &start,vector<vector<int>> &inp,int n,vector<int> &dp)
        {
                if(index>=n) return 0;
                if(dp[index]!=-1)
                {
                        return dp[index];
                }
                int obj=lower_bound(start.begin(),start.end(),inp[index][1])-start.begin();
                int ans1=inp[index][2]+find(obj,start,inp,n,dp);
                int ans2=find(index+1,start,inp,n,dp);
                return dp[index]=max(ans1,ans2);
        }
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
            int n=profit.size();
        vector<vector<int>> inp;
        vector<int> dp(n+1,-1);
            for(int i=0;i<startTime.size();i++)
            {
                    inp.push_back({startTime[i],endTime[i],profit[i]});
            }
            sort(inp.begin(),inp.end());
            sort(startTime.begin(),startTime.end());
            return find(0,startTime,inp,n,dp);
    }
};