class Solution {
public:
        int ans=-1;
        vector<bool> path_vis,vis;
        void dfs(vector<int> &edges,int src)
        {
                path_vis[src]=1;
                vis[src]=1;
                int next=edges[src];
                if(next==-1)
                {
                        path_vis[src]=0;
                }
                else if(!vis[next])
                {
                        dfs(edges,next);
                }
                else if(path_vis[src])
                {
                     int cnt = 0;
                     for(int i=0;i<edges.size();i++)
                        if(path_vis[i]) cnt++;
                     ans=max(ans,cnt);   
                }
                path_vis[src]=0;
        }
    int longestCycle(vector<int>& edges) {
            path_vis=vector<bool>(edges.size(),0);
            vis=vector<bool>(edges.size(),0);
         vector<int> indegree(edges.size(),0);
            int n=edges.size();
            for(int i=0;i<n;i++)
            {
                    if(edges[i]!=-1)
                    {
                    indegree[edges[i]]++;
                    }
            }
            vis=vector<bool>(n,false);
            queue<int> q;
            for(int i=0;i<n;i++)
            {
                    if(indegree[i]==0)
                    {
                            q.push(i);
                            vis[i]=1;
                    }
            }
            while(!q.empty())
            {
                    auto it=q.front();
                    q.pop();
                    int next=edges[it];
                    if(next!=-1)
                    {
                        if(--indegree[next]==0)
                        {
                            q.push(next); 
                            vis[next]=1;
                        }   
                    }
            }
            for(int i=0;i<n;i++)
            {
                    if(!vis[i])
                    {
                         dfs(edges,i);
                    }
            }
            return ans;
            
            
    }
};