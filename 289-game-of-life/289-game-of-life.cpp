class Solution {
public:
        int solve(vector<vector<int>> &board,int r,int c)
        {
        vector<int> x = {-1,-1,-1,0,0,1,1,1};
        vector<int> y = {-1,0,1,-1,1,-1,0,1};
                int count=0;
                for(int i=0;i<8;i++)
                {
                     if((r+x[i]<0) || (r+x[i]>=board.size()) || (c+y[i]<0) || (c+y[i]>=board[0].size()))        
                        continue;
                     if(board[r+x[i]][c+y[i]]==1)
                       count++;   
                }
                if(board[r][c])
                {
                        if(count<2 || count>3)
                        {
                                return 0;
                        }
                                return 1;
                 }
                else
                {
                        if(count==3)
                        {
                                return 1;
                        }
                }
                return 0;
                
        }
     void gameOfLife(vector<vector<int>>& board) 
     {
      int n=board.size();
            int m=board[0].size();
            vector<vector<int>> ans(n,vector<int>(m,0));
            for(int i=0;i<n;i++)
            {
                    for(int j=0;j<m;j++)
                    {
                            ans[i][j]=solve(board,i,j);
                    }
            }
            board=ans;
    }
};