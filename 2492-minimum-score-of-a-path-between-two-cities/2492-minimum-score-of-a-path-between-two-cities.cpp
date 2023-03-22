class Solution {
public:
        vector<pair<int,int>> inp[100001];
    int minScore(int n, vector<vector<int>>& roads) {
         for(auto it:roads)
            {
                    inp[it[0]].push_back({it[1],it[2]});
                    inp[it[1]].push_back({it[0],it[2]});
            }
            queue<int> q;
            q.push(1);
            int ans=INT_MAX;
            vector<int> vis(n+1,0);
            while(!q.empty())
            {
                    int x=q.front();
                    q.pop();
                    vis[x]=1;
                    for(auto it:inp[x])
                    {
                            if(!vis[it.first])
                            {
                                    ans=min(ans,it.second);
                                    q.push(it.first);
                            }
                    }
            }
            return ans;
            
    }
};