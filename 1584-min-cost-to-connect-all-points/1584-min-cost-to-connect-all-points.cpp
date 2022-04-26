class Solution {
public:
       int dis(vector<int>& v1, vector<int>& v2) {
        return abs(abs(v1[0]-v2[0]) + abs(v1[1]-v2[1]));
    } 
    int minCostConnectPoints(vector<vector<int>>& points)
    {
       int n = points.size();
	
       vector<vector<pair<int, int>>> adj(points.size());
	for(int i = 0; i < n; i++) 
        {
		for(int j = i + 1; j < n; j++) 
                {
			adj[i].push_back({j, dis(points[i], points[j])});
			adj[j].push_back({i, dis(points[i], points[j])});

                }
        }
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
     
            vector<bool> visited(n, false);
        pq.push({0, 0});
        int ans = 0;
            while(!pq.empty())
            {
                    auto it=pq.top();
                    pq.pop();
                    if(visited[it.second])
                    {
                            continue;
                    }
                    visited[it.second]=true;
                    int u = it.second;
                ans += it.first;
                for(auto gg: adj[u]) 
                {
                        if(!visited[gg.first]) 
                        {
                                pq.push({gg.second, gg.first});
                        }    
                }
            }
            return ans;
            
            
            
            
            
            return 0;
            
            
            
    }
};