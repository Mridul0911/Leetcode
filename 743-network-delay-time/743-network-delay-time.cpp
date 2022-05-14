class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n);
            for(auto gg:times)
            {
                    int x=gg[0];
                    int y=gg[1];
                    int z=gg[2];
                    adj[x-1].push_back({y-1,z});
                 
            }
            vector<int> dist(n+1,INT_MAX);
            dist[k-1]=0;
             
           priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k-1});
        dist[k-1]=0;
        while(!pq.empty())
        {
            int time=pq.top().first;
            int source=pq.top().second;
            pq.pop();
            for(auto itr: adj[source])
            {
                if(dist[itr.first]>(time+itr.second))
                {
                    pq.push({time+itr.second,itr.first});
                    dist[itr.first]=time+itr.second;
                }
            }
        }
            int ans=0;
            for(int i=0;i<n;i++)
            {
                    if(dist[i]<INT_MAX)
                       {
                               ans=max(ans,dist[i]);
                       }
                    else
                    {
                            return -1;
                    }
            }
    return ans;
    }
};