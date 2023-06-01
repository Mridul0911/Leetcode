class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
           int n = grid.size();
        
    vector<int> row={1, -1, 0, 0, 1, -1, 1, -1};
        vector<int> col={0, 0, 1, -1, 1, 1, -1, -1};
        if(grid[n-1][n-1]==1)
        {
            return -1;
        }
        if(grid[0][0]==1)
        {
            return -1;
        }
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},1});
        while(!q.empty())
        {
            int x=q.front().first.first;
            
            int y=q.front().first.second;
            int dis=q.front().second;
            cout<<x<<" "<<y<<" "<<dis<<endl;
            q.pop();
           // if(grid[x][y])  continue;
            grid[x][y] = 1;
            if(x==n-1 && y==n-1)
            {
                return dis;
            }
           // cout<<"Loop stsrat"<<endl;
            for(int i=0;i<8;i++)
            {
                int gg=x+row[i];
                int ff=y+col[i];
              //  cout<<gg<<" "<<ff<<endl;
                if(gg>=0 && gg<n && ff>=0 && ff<n && grid[gg][ff]==0)
                {
                    q.push({{gg,ff},dis+1});
                    grid[gg][ff]=1;
                }
            }
        }
       
        return -1;
        
    
    
    
    
    }
};