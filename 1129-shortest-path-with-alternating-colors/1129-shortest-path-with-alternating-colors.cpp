class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) 
    {
              ios_base::sync_with_stdio(0);
      cin.tie(0); cout.tie(0);
    
         vector<vector<pair<int,int>>> adj(n);
            for(auto it:red_edges)
            {
                    adj[it[0]].push_back({it[1],0});
            }
            for(auto it:blue_edges)
            {
                    adj[it[0]].push_back({it[1],1});
            }
            queue<pair<int,int>> qp;
            qp.push({0,-1});
            vector<int> dist(n,1e9);
            dist[0]=0;
            int count=1;
            vector<vector<vector<bool>>> vis(n,vector<vector<bool>>(n,vector<bool>(2,false)));
            
            while(!qp.empty())
            {
                    int size=qp.size();
                    for(int i=0;i<size;i++)
                    {
                            auto it=qp.front();
                            qp.pop();
                            for(auto gg:adj[it.first])
                            {
                                    cout<<gg.first<<" "<<gg.second<<endl;
                                if(vis[it.first][gg.first][gg.second]==false && gg.second!=it.second)    
                                {
                                        dist[gg.first]=min(count,dist[gg.first]);
                                        vis[it.first][gg.first][gg.second]=true;
                                        qp.push({gg.first,gg.second});
                                }
                            }
                    }
                    count++;
            }
            for(int i=0;i<n;i++)
            {
                    if(dist[i]==1e9)
                    {
                            dist[i]=-1;
                    }
            }
            return dist;
            
    }
};