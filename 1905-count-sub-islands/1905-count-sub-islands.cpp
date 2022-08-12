class Solution {
public:
        void find(int i,int j,vector<vector<int>> &grid2,vector<vector<int>> &grid1,bool &flag)
        {
                if(i<0 || j<0 || i>=grid2.size() || j>=grid2[0].size())
                {
                        return;
                }
                if(grid2[i][j]==1 && grid1[i][j]==0)
                {
                        flag=false;
                }
                if(grid2[i][j]==0)
                {
                        return;
                }
                grid2[i][j]=0;
                find(i+1,j,grid2,grid1,flag);
                find(i,j+1,grid2,grid1,flag);
                find(i-1,j,grid2,grid1,flag);
                find(i,j-1,grid2,grid1,flag);
        }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
         int n=grid2.size();
            int m=grid2[0].size();
            int finalans=0;
            for(int i=0;i<n;i++)
            {
                    for(int j=0;j<m;j++)
                    {
                            if(grid2[i][j]==1)
                            {
                                    bool ans=true;
                                    find(i,j,grid2,grid1,ans);
                                    finalans+=ans;
                            }
                    }
            }
            return finalans;
    }
};