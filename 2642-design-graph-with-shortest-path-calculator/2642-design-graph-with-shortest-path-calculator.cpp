class Graph {
public:
    int gg;
    vector<vector<pair<int,int>>> adj;
    Graph(int n, vector<vector<int>>& edges) {
        gg=n;
        adj.resize(gg);
        for(auto it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> dist(gg,INT_MAX);
        dist[node1]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,node1});
        while(!pq.empty())
        {
            int dis=pq.top().first;
            int no=pq.top().second;
            pq.pop();
            if(no==node2)
            {
                return dis;
            }
            if(dis>dist[no])
            {
                continue;
            }
            for(auto it:adj[no])
            {
                int hh=it.first;
                int d1=it.second;
                if(dist[hh]>d1+dist[no])
                {
                    dist[hh]=d1+dist[no];
                    pq.push({dist[hh],hh});
                }
            }
            
        }
        return -1;
    }
};