class Solution {
public:
        bool dfs(vector<vector<char>> &board,vector<vector<bool>> &vis,string word,int gg,int x,int y)
        {
             if(gg==word.size())
        {
            return true;
        }
        if(x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && vis[x][y] == false && word[gg] == board[x][y])
        {
            vis[x][y] = true;
           if(dfs(board,vis,word,gg+1,x+1,y) || dfs(board,vis,word,gg+1,x-1,y) || dfs(board,vis,word,gg+1,x,y+1) || dfs(board,vis,word,gg+1,x,y-1))
         {
             return true;
         }
         vis[x][y] = false;
           
       }
       return false;   
        }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> vis(board.size(),vector<bool>(board[0].size()));
            for(int i=0;i<board.size();i++)
            {
                    for(int j=0;j<board[0].size();j++)
                    {
                            if(word[0]==board[i][j])
                            {
                                    if(dfs(board,vis,word,0,i,j)) return true;
                            }
                    }
            }
            return false;
            }
};