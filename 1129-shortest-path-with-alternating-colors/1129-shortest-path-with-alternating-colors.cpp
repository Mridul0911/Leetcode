class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<redEdges.size();i++)
        {
            adj[redEdges[i][0]].push_back({redEdges[i][1],0});    
        }
        for(int i=0;i<blueEdges.size();i++)
        {
            adj[blueEdges[i][0]].push_back({blueEdges[i][1],1});
        }
        vector<vector<int>>dist(n,vector<int>(2,-1));;
        queue<pair<int,int>>q;
        q.push({0,1});
        q.push({0,0});
        dist[0][0]=0;
        dist[0][1]=0;
        while(!q.empty())
        {
            int v = q.front().first;
            int col = q.front().second;
            q.pop();
            for(auto it:adj[v])
            {
                if(it.second==col||dist[it.first][it.second]!=-1)
                    continue;
                dist[it.first][it.second] = 1+ dist[v][col];
                q.push({it.first,it.second});
            }
        }
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++)
        {
            if(dist[i][0]==-1&&dist[i][1]==-1)
                continue;
            else if(dist[i][0]==-1||dist[i][1]==-1)
            {
                if(dist[i][0]!=-1)
                ans[i]=dist[i][0];
            if(dist[i][1]!=-1)
                ans[i]=dist[i][1];    
            }
            else
                ans[i]=min(dist[i][1],dist[i][0]);
        }
        return ans;
    }
};