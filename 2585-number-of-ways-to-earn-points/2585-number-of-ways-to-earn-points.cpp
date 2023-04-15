class Solution {
public:
    long long mod=1e9+7;
    long long find(int target,vector<vector<int>> &types,int index,vector<vector<long long>> &dp)
    {
        if(index>=types.size())
        {
            return target==0;
        }
        if(target<0)
        {
            return 0;
        }
        if(dp[index][target]!=-1)
        {
            return dp[index][target];
        }
        long long ans=find(target,types,index+1,dp)%mod;
        for(int i=0;i<types[index][0];i++)
        {
            if((target-(i+1)*(types[index][1]))>=0)
            {
                ans+=(find((target-(i+1)*(types[index][1])),types,index+1,dp)%mod);
            }
            else
            {
                break;
            }
        }
        return dp[index][target]=ans%mod;
    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n=types.size();
        vector<vector<long long>> dp(n+1,vector<long long>(target+1,-1));
        return find(target,types,0,dp)%mod;
    }
};