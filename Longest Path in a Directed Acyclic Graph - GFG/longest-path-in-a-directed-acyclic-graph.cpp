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
            vector<pair<int,int>> adj[v];
            for(int i=0;i<edges.size();i++)
            {
                adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            }
            vector< int>dist(v,INT_MIN);
            priority_queue<pair<int,int>> pq;
            pq.push({src,0});
            dist[src]=0;
            while(!pq.empty())
            {
                pair<int,int>p=pq.top();
                pq.pop();
                int x=p.first;
                int y=p.second;
                for(auto it:adj[x])
                {
                    if(it.second+y>dist[it.first])
                    {
                        dist[it.first]=it.second+y;
                        pq.push({it.first,it.second+y});
                    }
                }
            }
            vector< int>ans;
            for(int i=0;i<v;i++)
            {
                if(dist[i]==INT_MIN)ans.push_back(INT_MIN);
                else ans.push_back(dist[i]);
            }
            return ans;
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