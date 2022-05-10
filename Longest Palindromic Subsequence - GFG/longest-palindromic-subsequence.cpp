// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
            int m=text2.size();
            vector<vector<int>> dp(n+1,vector<int>(m+1,0));
            for(int i=0;i<=m;i++)
            {
                    dp[0][i]=0;
            }
            for(int i=0;i<=n;i++)
            {
                    dp[i][0]=0;
            }
            for(int i=1;i<=n;i++)
            {
                    for(int j=1;j<=m;j++)
                    {
                            if(text1[i-1]==text2[j-1])
                            {
                                    dp[i][j]=1+dp[i-1][j-1];
                            }
                            else
                            {
                            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                            }
                    }
            }
            return dp[n][m];
    }
    int longestPalinSubseq(string s) {
        //code here
        string g=s;
            reverse(s.begin(),s.end());
            return longestCommonSubsequence(s,g);
    }
};

// { Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends