class Solution {
public:
        bool isValid(int row,int column,vector<vector<char>> &board,char c)
        {
                 for(int i=0;i<9;i++)
                 {
                        if(board[i][column]==c)
                        {
                                return false;
                        }
                        if(board[row][i]==c)
                        {
                                return false;
                        }
                        if(board[3*(row/3)+i/3][3*(column/3)+i%3]==c)
                        {
                                return false;
                        }
                }
                return true;    
        }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++)
                if(board[i][j]!='.'){
                    char temp=board[i][j];
                    board[i][j]='+';
                    if(!isValid(i,j,board,temp)){
                        return false;
                    }
                    board[i][j]=temp;
                }
        }
        return true;
   }
};