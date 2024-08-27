class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) 
    {
            vector<vector<pair<int,double>>> adj(n);
            int i=0;
            for(auto gg:edges)
            {
                    adj[gg[0]].push_back({gg[1],succProb[i]});
                    adj[gg[1]].push_back({gg[0],succProb[i]});
               i++;            
            }
            vector<double> dis(n,0);
            priority_queue<pair<int,double>,vector<pair<int,double>>> pq;
            pq.push({1,start});
            dis[start]=1;
            while(!pq.empty())
            {
                    int gg=pq.top().second;
                    pq.pop();
                    for(auto hh:adj[gg])
                    {
                          int v=hh.first;
                            double weight=hh.second;
                            if(dis[v]<dis[gg]*weight)
                            {
                                    dis[v]=dis[gg]*weight;
                                    pq.push({dis[v],v});
                            }
                    }
            }
            return dis[end];
    }
};