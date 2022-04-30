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
            vector<vector<int>> dp(n+1,vector<int>(n+1,0));
            vector<int> front(n,0);
            vector<int> curr(n,0);
            for(int i=0;i<n;i++)
            {
                    front[i]=triangle[n-1][i];
            }
            for(int i=n-2;i>=0;i--)
            {
                    for(int j=i;j>=0;j--)
                    {
                            int down=triangle[i][j]+front[j];
                            int dig=triangle[i][j]+front[j+1];
                            curr[j]=min(down,dig);
                    }
                    front=curr;
            }
            return front[0];
    }
};