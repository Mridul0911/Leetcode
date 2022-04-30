class Solution {
public:
        int find(int i,int j,vector<vector<int>> &traingle,vector<vector<int>> &dp)
        {
                if(i==traingle.size()-1)
                {
                        return traingle[traingle.size()-1][j];
                }
                if(dp[i][j]!=-1)
                {
                        return dp[i][j];
                }
                int down=traingle[i][j]+find(i+1,j,traingle,dp);
                int dig=traingle[i][j]+find(i+1,j+1,traingle,dp);
                return dp[i][j]=min(down,dig);
        }
    int minimumTotal(vector<vector<int>>& triangle) {
            int n=triangle.size();
            vector<vector<int>> dp(n,vector<int>(n,-1));
      return find(0,0,triangle,dp);
    }
};