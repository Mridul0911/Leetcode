// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void dfs(int r,int c,int n,vector<vector<int>> &adj,vector<string> &ans,string gg,vector<vector<bool>> &vis)
    {
        if(r<0 || r>=n || c<0 || c>=n || adj[r][c]==0 || vis[r][c]==1)
        {
            return;
        }
        if(r==n-1 && c==n-1)
        {
            ans.push_back(gg);
            return;
        }
        vis[r][c]=1;
        dfs(r-1,c,n,adj,ans,gg+"U",vis);
        dfs(r,c-1,n,adj,ans,gg+"L",vis);
        dfs(r+1,c,n,adj,ans,gg+"D",vis);
        dfs(r,c+1,n,adj,ans,gg+"R",vis);
        vis[r][c]=0;
    }
    vector<string> findPath(vector<vector<int>> &adj, int n) {
        // Your code goes here
        vector<string> ans;
        vector<vector<bool>> vis(n,vector<bool>(n,0));
        dfs(0,0,n,adj,ans,"",vis);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends