class Solution {
public:
        int count=0;
      bool isValid(int row,int col,vector<string> board,int n)
        {
                int currRow=row;
                int currColumn=col;
                while(row>=0 && col>=0)
                {
                        if(board[row][col]=='Q') return false;
                        row--;
                        col--;
                }
                row=currRow;
                col=currColumn;
                while(col>=0)
                {
                        if(board[row][col]=='Q')
                        {
                                return false;
                        }
                        col--;
                }
                row=currRow;
                col=currColumn;
                while(row<n && col>=0)
                {
                        if(board[row][col]=='Q')
                        {
                                return false;
                        }
                        row++;
                        col--;
                }
                return true;
        }
        void solve(vector<string> &board,int n,int col)
        {
                if(col==n)
                {
                        count++;
                        return;
                }
                for(int row=0;row<n;row++)
                {
                        if(isValid(row,col,board,n))
                        {
                                board[row][col]='Q';
                                solve(board,n,col+1);
                                board[row][col]='.';
                        }
                }
        }
    int totalNQueens(int n) {
            vector<string> board(n);
            string s(n,'.');
            count=0;
            for(int i=0;i<n;i++)
            {
                    board[i]=s;
            }
            solve(board,n,0);
            return count;
    }
};