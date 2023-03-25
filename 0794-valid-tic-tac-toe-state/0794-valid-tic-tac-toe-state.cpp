class Solution {
public:
        
    bool validTicTacToe(vector<string>& board) {
        int x_count=0;
            int o_count=0;
            for(int i=0;i<board.size();i++)
            {
                    for(int j=0;j<board.size();j++)
                    {
                          //  cout<<board[i][j]<<" ";
                            if(board[i][j]=='O')
                            {
                                    o_count++;
                            }
                            if(board[i][j]=='X')
                            {
                                    x_count++;
                            }
                    }
                   // cout<<endl;
            }
            cout<<x_count<<" "<<o_count<<endl;
            if(o_count>x_count || x_count-o_count>1)
            {
                    return false;
            }
            bool x_win=false;
            bool o_win=false;
            for(auto it:board)
            {
                    if(it=="XXX")
                    {
                            x_win=true;
                    }
                    if(it=="OOO")
                    {
                            o_win=true;
                    }
            }
            for(int i=0;i<3;i++)
            {
                  if(board[0][i]=='X' && board[1][i]=='X' && board[2][i]=='X')  
                  {
                          x_win=true;
                  }
                  if(board[0][i]=='O' && board[1][i]=='O' && board[2][i]=='O')  
                  {
                          o_win=true;
                  }  
            }
            if(board[0][0]=='X' && board[1][1]=='X' && board[2][2]=='X')
            {
                    x_win=true;
            }
            if(board[0][0]=='O' && board[1][1]=='O' && board[2][2]=='O')
            {
                    o_win=true;
            }
            if(board[0][2]=='X' && board[1][1]=='X' && board[2][0]=='X')
            {
                    x_win=true;
            }
            if(board[0][2]=='O' && board[1][1]=='O' && board[2][0]=='O')
            {
                    o_win=true;
            }
            if(x_win && o_win)
            {
                    return false;
            }
            cout<<x_win<<" "<<o_win<<endl;
            if(x_win && o_count>=x_count)
            {
                    return false;
            }
            if(o_win && x_count>o_count)
            {
                    return false;
            }
            return true;
     }
};