class Solution {
public:
        int find(int i,int j,int x,vector<vector<int>> &matrix,vector<vector<int>> &dp)
        {
                int n=matrix.size();
                int m=matrix[0].size();
                if(i<0 || i>=n || j<0 || j>=m || x >= matrix[i][j]) return 0;
                if(dp[i][j]!=-1)
                {
                        return dp[i][j];
                }
                int up=find(i-1,j,matrix[i][j],matrix,dp);
                int down=find(i+1,j,matrix[i][j],matrix,dp);
                int left=find(i,j-1,matrix[i][j],matrix,dp);
                int right=find(i,j+1,matrix[i][j],matrix,dp);
                return dp[i][j]=max({left,right,down,up})+1;
        }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
            int m=matrix[0].size();
            vector<vector<int>> dp(n,vector<int> (m+1,-1));
            int ans=0;
            for(int i=0;i<n;i++)
            {
                    for(int j=0;j<m;j++)
                    {
                      ans=max(ans,find(i,j,-1,matrix,dp));      
                    }
            }
       return ans;        
}
};