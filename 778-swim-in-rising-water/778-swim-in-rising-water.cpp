class Solution {
public:
        int vis[51][51];
        int dp[51][51][2601];
        int find(int i,int j,vector<vector<int>> &grid,int time)
        {
                if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || vis[i][j]==1)
                {
                        return 1e6;
                }
                if(dp[i][j][time]!=-1)
                {
                        return dp[i][j][time];
                }
                int hh=time+max(0,grid[i][j]-time);
                if(i==grid.size()-1 && j==grid[0].size()-1)
                        return hh;
                vis[i][j]=1;
                long long cond1=find(i+1,j,grid,hh);
                long long cond2=find(i-1,j,grid,hh);
                long long cond3=find(i,j+1,grid,hh);
                long long cond4=find(i,j-1,grid,hh);
                vis[i][j]=0;
                return dp[i][j][time]=min({cond1,cond2,cond3,cond4});
        }
    int swimInWater(vector<vector<int>>& grid) {
            memset(vis,0,sizeof(vis));
            memset(dp,-1,sizeof(dp));
            return find(0,0,grid,0);
    }
};