class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<pair<int,int>>adj[n+1];
         vector<int>distr(n+1,1e9);
         vector<int>distb(n+1,1e9);
            for(int i=0;i<redEdges.size();i++)
            {
                    adj[redEdges[i][0]].push_back({redEdges[i][1],0});
            }
            for(int i=0;i<blueEdges.size();i++)
            {
                    adj[blueEdges[i][0]].push_back({blueEdges[i][1],1});
            }
            distr[0]=0;
            distb[0]=0;
            queue<pair<int,int>>q;
            q.push({0,-1});
            while(!q.empty())
            {
                    int u=q.front().first;
                    int v=q.front().second;
                    q.pop();
                    for(auto it:adj[u])
                    {
                            if(v==-1)
                            {
                                    if(it.second==0)
                                    {
                                            if(distr[it.first]>1+distb[u])
                                            {
                                            distr[it.first]=1;
                                            q.push({it.first,0});
                                            }
                                    }
                                    else
                                    {
                                            if(distb[it.first]>1+distr[u])
                                            {
                                            distb[it.first]=1;
                                            q.push({it.first,1});
                                            }
                                    }
                            }
                            else if(v==0)
                            {
                                  if(it.second==1)
                                  {
                                          if(distb[it.first]>1+distr[u])
                                          {
                                                  distb[it.first]=1+distr[u];
                                                  q.push({it.first,1});
                                          }
                                  }
                            }
                            else
                            {
                                   if(it.second==0) 
                                   {
                                           if(distr[it.first]>1+distb[u])
                                           {
                                                   distr[it.first]=1+distb[u];
                                                   q.push({it.first,0});
                                           }
                                   }
                            }
                    }
            }
            vector<int>ans;
            for(int i=0;i<n;i++)
            {
                    int x=min(distr[i],distb[i]);
                    if(x==1e9)ans.push_back(-1);
                    else ans.push_back(x);
            }
            return ans;
    }
};