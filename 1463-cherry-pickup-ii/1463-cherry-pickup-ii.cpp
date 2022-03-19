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
  
    int cherryPickup(vector<vector<int>>& grid) 
    {
            int n=grid.size();
            int m=grid[0].size();
      vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m, 0)));

  for (int j1 = 0; j1 < m; j1++) {
    for (int j2 = 0; j2 < m; j2++) {
      if (j1 == j2)
        dp[n-1][j1][j2] = grid[n-1][j1];
      else
        dp[n-1][j1][j2] = grid[n-1][j1]+grid[n-1][j2];
    }
  }

  //Outer Nested Loops for travering DP Array
  for (int i = n - 2; i >= 0; i--) {
    for (int j1 = 0; j1 < m; j1++) {
      for (int j2 = 0; j2 < m; j2++) {

        int maxi = INT_MIN;

        //Inner nested loops to try out 9 options
        for (int di = -1; di <= 1; di++) {
          for (int dj = -1; dj <= 1; dj++) {

            int ans;

            if (j1 == j2)
              ans = grid[i][j1];
            else
              ans = grid[i][j1] + grid[i][j2];

            if ((j1 + di < 0 || j1 + di >= m) ||
              (j2 + dj < 0 || j2 + dj >= m))

              ans += -1e9;
            else
              ans += dp[i + 1][j1 + di][j2 + dj];

            maxi = max(ans, maxi);
          }
        }
        dp[i][j1][j2] = maxi;
      }
    }
  }

  return dp[0][0][m - 1];
    }
    };