class Solution {
public:
    int find(vector<vector<int>> &piles,int k,int index,vector<vector<int>> &dp)
    {
        if(index>=piles.size())
        {
            return 0;
        }
        if(dp[index][k]!=-1)
        {
            return dp[index][k];
        }
        int maxi=0;
        int sum=0;
        maxi=max(maxi,find(piles,k,index+1,dp));
        for(int i=0;i<piles[index].size();i++)
        {
            sum+=piles[index][i];
            if(k-(i+1)>=0)
            {
                maxi=max(maxi,sum+find(piles,k-(i+1),index+1,dp));
            }
        }
        return dp[index][k]=maxi;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return find(piles,k,0,dp);
    }
};