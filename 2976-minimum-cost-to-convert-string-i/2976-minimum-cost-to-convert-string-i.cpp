class Solution {
public:
    void bfs(int node,vector<pair<int,int>>adj[],vector<vector<int>>&dist)
    {
        vector<int>vis(26,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,node});
        while(!pq.empty())
        {
            int curr=pq.top().second,wt=pq.top().first;
            pq.pop();
            if(vis[curr])continue;
            vis[curr]=1;
            dist[node][curr]=min(dist[node][curr],wt);
            for(auto &ngb:adj[curr])
            {
                if(vis[ngb.first])continue;
                pq.push({ngb.second+wt,ngb.first});
            }
        }
    }
    long long minimumCost(string source, string target, vector<char>& ori, vector<char>& ch, vector<int>& cost) {
        map<pair<int,int>,int>mp;
        for(int i=0;i<ori.size();i++)
        {
           int u=(ori[i]-'a');
           int v=(ch[i]-'a');
           if(mp.count({u,v}))mp[{u,v}]=min(mp[{u,v}],cost[i]);
           else mp[{u,v}]=cost[i];
        }
        vector<pair<int,int>>adj[27];
        for(auto &iter:mp)
        {
            int u=iter.first.first,v=iter.first.second,wt=iter.second;
            adj[u].push_back({v,wt});
        }
        vector<vector<int>>dist(26,vector<int>(26));
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                dist[i][j]=INT_MAX;
            }
        }
        for(int i=0;i<26;i++)
        {
            bfs(i,adj,dist);
        }
        long long ans=0;
        for(int i=0;i<source.size();i++)
        {
            int u=(source[i]-'a');
            int v=(target[i]-'a');
            if(dist[u][v]==INT_MAX)return -1;
            ans+=dist[u][v];
        }
        return ans;
    }
};