// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
      vector <int> maximumDistance(vector<vector<int>> edges,int v,int e,int src)
      {
            // code here
            vector<vector<int>> adj[v];
            vector<int> indegree(v,0);
            vector<int> dist(v,INT_MIN);
            
            for(int i=0;i<e;i++)
            {
                 adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
                 indegree[edges[i][1]]++;
            }
            queue<int> q;
           
            for(int i=0;i<v;i++)
            {
                if(indegree[i]==0)
                {
                    q.push(i);
                }
            }
            dist[src] = 0;
            vector<int> ans;
            while(!q.empty())
            {
                int x=q.front();
                q.pop();
                ans.push_back(x);
                for(auto it:adj[x])
                {
                    if(dist[x]!=INT_MIN)
                    {
                        dist[it[0]]=max(dist[it[0]],dist[x]+it[1]);
                    }
                    indegree[it[0]]--;
                    if(indegree[it[0]]==0)
                    {
                        q.push(it[0]);
                    }
                }
            }
            return dist;
      }
};

// { Driver Code Starts.

int main() {
  
    int t;
    cin>>t;
    while(t--)
    {

        int v,e;
        cin>>v>>e;
     
        int src;
        cin>>src;
        vector<vector<int>> edges(e,vector<int> (3));
        for(auto &j:edges)
          cin>>j[0]>>j[1]>>j[2];

        Solution s;
        vector <int> ans=s.maximumDistance(edges,v,e,src);
        for(auto j:ans)
        {
            if(j==INT_MIN)
              cout<<"INF ";
            else
              cout<<j<<" ";
        }
        cout<<endl;
    } 
    return 0;
 
}  // } Driver Code Ends