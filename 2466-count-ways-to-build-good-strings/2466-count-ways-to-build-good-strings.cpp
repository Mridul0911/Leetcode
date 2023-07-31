class Solution {
public:
    int mod=1e9+7;
    int find(int length,int low,int high,int zero,int one,vector<int> &dp)
    {
        if(length>=high)
        {
            return 0;
        }
        if(dp[length]!=-1)
        {
            return dp[length];
        }
        long long a=find(length+zero,low,high,zero,one,dp);
        if(zero+length>=low && zero+length<=high)
        {
            a++;
        }
        long long b=find(length+one,low,high,zero,one,dp);
        if(one+length>=low && one+length<=high)
        {
            b++;
        }
        return dp[length]=(a+b)%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(1e6+1,-1);
        return find(0,low,high,zero,one,dp);
    }
};