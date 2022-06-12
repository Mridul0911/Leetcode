// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int find(int i,int j,int x,vector<vector<int>> &matrix,vector<vector<int>> &dp)
        {
                int n=matrix.size();
                int m=matrix[0].size();
                if(i<0 || i>=n || j<0 || j>=m || x >= matrix[i][j]) return 0;
                if(dp[i][j]!=-1)
                {
                        return dp[i][j];
                }
                int up=find(i-1,j,matrix[i][j],matrix,dp);
                int down=find(i+1,j,matrix[i][j],matrix,dp);
                int left=find(i,j-1,matrix[i][j],matrix,dp);
                int right=find(i,j+1,matrix[i][j],matrix,dp);
                return dp[i][j]=max({left,right,down,up})+1;
        }
    int longestIncreasingPath(vector<vector<int>>& matrix, int n, int m) {

        // Code here
        vector<vector<int>> dp(n,vector<int> (m+1,-1));
            int ans=0;
            for(int i=0;i<n;i++)
            {
                    for(int j=0;j<m;j++)
                    {
                      ans=max(ans,find(i,j,-1,matrix,dp));      
                    }
            }
       return ans;  
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.longestIncreasingPath(matrix, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends