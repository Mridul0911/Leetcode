class Solution {
public:
        int ans;
        bool find(vector<vector<int>> &grid,int row,int col)
        {
                if(row==grid.size())
                {
                        ans=col;
                        return true;
                }
                if(col==0 && grid[row][col]==-1 || ((col==(grid[0].size()-1)) && grid[row][col]==1))
                {
                        return false;
                }
                if(grid[row][col]==1)
                {
                        if(grid[row][col+1]==1)
                        {
                                return find(grid,row+1,col+1);
                        }
                        else
                        {
                                return false;
                        }
                }
                else if(grid[row][col]==-1)
                {
                        if(grid[row][col-1]==-1)
                        {
                                return find(grid,row+1,col-1);
                        }
                        else
                        {
                                return false;
                        }
                }
                return false;
        }
    vector<int> findBall(vector<vector<int>>& grid) {
        int n=grid.size();
            int m=grid[0].size();
            vector<int> ans1;
            for(int i=0;i<m;i++)
            {
                    if(find(grid,0,i))
                    {
                            ans1.push_back(ans);
                    }
                    else
                    {
                            ans1.push_back(-1);
                    }
            }
            return ans1;
    }
};