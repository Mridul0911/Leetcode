class Solution {
public:
    int find(int am,vector<int> &coins,int index,vector<vector<int>> &dp)
    {
        if(index<0)
        {
            return 0;
        }
        if(am==0)
        {
            return 1;
        }
        if(dp[index][am]!=-1)
        {
            return dp[index][am];
        }
        if(coins[index]>am)
        {
            return dp[index][am]=find(am,coins,index-1,dp);
        }
        return dp[index][am]=find(am-coins[index],coins,index,dp)+find(am,coins,index-1,dp);
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        return find(amount,coins,coins.size()-1,dp);
    }
};