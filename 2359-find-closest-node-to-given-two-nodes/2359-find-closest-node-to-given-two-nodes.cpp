class Solution {
public:
       void find(int src,vector<int> &dist1,vector<int> adj[]) 
       {
               dist1[src]=0;
               queue<int> q;
               q.push(src);
               while(!q.empty())
               {
                       int node_it=q.front();
                       q.pop();
                       for(auto it:adj[node_it])
                       {
                               if(dist1[it]>dist1[node_it]+1)
                               {
                                       q.push(it);
                                       dist1[it]=dist1[node_it]+1;
                               }
                       }
               }
       }
     int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++)
        {
            if(edges[i]!=-1)
            adj[i].push_back(edges[i]);
        }
             vector<int> dist1(n+1,INT_MAX);
             vector<int> dist2(n+1,INT_MAX);
        find(node1,dist1,adj);
        find(node2,dist2,adj);
             int i=0;
             int idx=-1;
             int ans=INT_MAX;
         for(int i=0;i<n;i++)
         {
           //     cout<<dist1[i]<<" "<<dist2[i]<<endl;
                  int gg=max(dist1[i],dist2[i]);
                 if(ans>gg)
                 {
                         ans=gg;
                         idx=i;
                 }
         }
         return idx;
    }
};