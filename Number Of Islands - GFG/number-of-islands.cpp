//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void dfs(vector<vector<int>> &g, int i, int j, int n, int m){
       if(i+1<n && g[i+1][j]==1){
           g[i+1][j]=-1;
           dfs(g,i+1,j,n,m);
       }
       
       if(i-1>=0 && g[i-1][j]==1){
           g[i-1][j]=-1;
           dfs(g,i-1,j,n,m);
       }
       
       if(j+1<m && g[i][j+1]==1){
           g[i][j+1]=-1;
           dfs(g,i,j+1,n,m);
       }
       
       if(j-1>=0 && g[i][j-1]==1){
           g[i][j-1]=-1;
           dfs(g,i,j-1,n,m);
       }
   }
  
   int find(vector<vector<int>> &g){
       int n=g.size();
       int m=g[0].size();
       int ans=0;
       
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(g[i][j]==1){
                   ans++;
                   dfs(g,i,j,n,m);
               }
           }
       }
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(g[i][j]==-1){
                   g[i][j]=1;
               }
           }
       }
       return ans;
   }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &o) {
        // code here
        vector<int> ans;
        vector<vector<int>> g(n,vector<int>(m,0));
        for(auto &x:o){
            g[x[0]][x[1]]=1;
            int num = find(g);
            ans.push_back(num);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends