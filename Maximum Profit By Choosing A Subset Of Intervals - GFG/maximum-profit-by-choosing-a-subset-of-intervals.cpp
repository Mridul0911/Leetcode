//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  bool static cmp(vector<int> &a,vector<int> &b)
  {
      if(a[0]!=b[0])
      {
          return a[0]-b[0];
      }
      else
      {
          return a[1]-b[1];
      }
  }
  int find_next(vector<vector<int>> &intervals,int ind,int n,int prev)
  {
      while(ind<n)
      {
        if(intervals[ind][0]>=prev)
        {
            break;
        }
        else
        {
            ind++;
        }
      }
      return ind;
  }
    int find(int n,vector<vector<int>> &intervals,int ind,vector<int> &dp)
    {
        if(ind>=n)
        {
            return 0;
        }
        if(dp[ind]!=-1)
        {
            return dp[ind];
        }
        int not_pick=find(n,intervals,ind+1,dp);
        int next_ind=find_next(intervals,ind+1,n,intervals[ind][1]);
        int pick=intervals[ind][2]+find(n,intervals,next_ind,dp);
        return dp[ind]=max(pick,not_pick);
    }
    int maximum_profit(int n, vector<vector<int>> &intervals) {
        // Write your code here.
        int ans=0;
        vector<int> dp(n+1,-1);
        sort(intervals.begin(),intervals.end());
        return find(n,intervals,0,dp);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends