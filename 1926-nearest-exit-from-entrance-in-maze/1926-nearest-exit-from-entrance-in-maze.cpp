class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance)     {
        queue<pair<int,int>> q;
            q.push({entrance[0],entrance[1]});
            int moves=1;
           int n=maze.size();
            int m=maze[0].size();
            maze[entrance[0]][entrance[1]]='+';
            vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
            while(!q.empty())
            {
                    int size=q.size();
                    for(int i=0;i<size;i++)
                    {
                            auto it=q.front();
                            q.pop();
                            for(int j=0;j<4;j++)
                            {
                                    int x=it.first+dir[j][0];
                                    int y=it.second+dir[j][1];
                                    if(x>=n || y>=m || x<0 || y<0 || maze[x][y]=='+' )
                                    {
                                            continue;
                                    }
                                    if(x==n-1 || y==m-1 || x==0 || y==0)
                                    {
                                            return moves;
                                    }
                                    maze[x][y]='+';
                                    q.push({x,y});
                            }
                    }
                    moves++;
            }
            return -1;
    }
};