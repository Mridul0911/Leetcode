class Solution {
public:
//    int fever(vector<vector<int>> &grid,int i,int j1,int j2,int r,int c)
// {
//     if(j1<0 || j1>=c || j2<0 || j2>=c){
//         return -1e8;
//     }
//     if(i==r-1)
//     {
//         if(j1==j2)
//         {
//             return grid[i][j1];
//         }
//         else
//         {
//             return grid[i][j1]+grid[i][j2];
//         }
//     }
//     int maxi=-1e8;
//     for(int jj1=-1;jj1<=1;jj1++)
//     {
//         for(int jj2=-1;jj2<=1;jj2++)
//         {
//             int value=0;
//             if(j1==j2)
//             {
//                 value+=grid[i][j1];
//             }
//             else
//             {
//                 value+=(grid[i][j1]+grid[i][j2]);
//             }
//             value+=fever(grid,i+1,j1+jj1,j2+jj2,r,c);
//             maxi=max(maxi,value);
//         }
//     }
//     return maxi;
// }
        int fever(vector<vector<int>> &grid,int i,int j1,int j2,int r,int c,vector<vector<vector<int>>> &dp)
{
    if(j1<0 || j1>=c || j2<0 || j2>=c){
        return -1e8;
    }
    if(i==r-1)
    {
        if(j1==j2)
        {
            return grid[i][j1];
        }
        else
        {
            return grid[i][j1]+grid[i][j2];
        }
    }
                if(dp[i][j1][j2]!=-1)
                {
                        return dp[i][j1][j2];
                }
    int maxi=-1e8;
    for(int jj1=-1;jj1<=1;jj1++)
    {
        for(int jj2=-1;jj2<=1;jj2++)
        {
            int value=0;
            if(j1==j2)
            {
                value+=grid[i][j1];
            }
            else
            {
                value+=(grid[i][j1]+grid[i][j2]);
            }
            value+=fever(grid,i+1,j1+jj1,j2+jj2,r,c,dp);
            maxi=max(maxi,value);
        }
    }
    return dp[i][j1][j2]=maxi;
}
  
    int cherryPickup(vector<vector<int>>& grid) {
       int m=grid.size();
      int n=grid[0].size();
            vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
     return fever(grid,0,0,n-1,m,n,dp);
    }
};