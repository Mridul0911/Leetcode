class Solution {
public:
    int solve(vector<int> &cuts,int i,int j,vector<vector<int>> &dp){
        if(j<i){
            return 0;
        }
            if(dp[i][j]!=-1)
            {
                    return dp[i][j];
            }
        int minn = 1e9;
        for(int k=i;k<=j;k++){
            int cost = cuts[j+1]-cuts[i-1] + solve(cuts,i,k-1,dp) + solve(cuts,k+1,j,dp);
            minn = min(cost,minn);
        }
        return dp[i][j]=minn;
    }

     int minCost(int n, vector<int>& cuts) 
     {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
             
        sort(cuts.begin(),cuts.end());
             vector<vector<int>> dp(c+1,vector<int> (c+1,-1));
        return solve(cuts,1,c,dp);
    }
};