// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  long find(int s[],int target,int ind,vector<vector<long>> &dp)
  {
      if(ind==0)
      {
          long ans;
          if(target%s[ind]==0) ans=1;
          else ans=0;
          return ans;
      }
      if(dp[ind][target]!=-1)
      {
          return dp[ind][target];
      }
      long notTake=find(s,target,ind-1,dp);
      long take=0;
      if(target-s[ind]>=0)
      {
          take=find(s,target-s[ind],ind,dp);
      }
      return dp[ind][target]=take+notTake;
  }
    long long int count(int S[], int m, int n) {
        vector<vector<long>> dp(m,vector<long>(n+1,-1));
       return find(S,n,m-1,dp);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends