class Solution {
public:
    int find(int i,int j,vector<vector<char>> &mt,vector<vector<int>> &dp)
    {
        if(i>=mt.size() || j>=mt[0].size() || mt[i][j]=='0')
        {
            return 0;    
        }
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=1+min(find(i+1,j,mt,dp),min(find(i+1,j+1,mt,dp),find(i,j+1,mt,dp)));
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int n,m;
        n=matrix.size();
        int ans=0;
    
        m=matrix[0].size();
        int count=0;
      //  vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(n+m+1,-1)));
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               if(matrix[i][j]=='1')
               {
                   ans=max(ans,find(i,j,matrix,dp));
               }
            }
        }
        return ans*ans;
    }
};