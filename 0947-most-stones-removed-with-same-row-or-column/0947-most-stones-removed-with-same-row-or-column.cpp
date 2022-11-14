class Solution {
public:
        void dfs(vector<vector<int>> &stones,vector<int> &vis,int &cnt,int src)
        {
                cnt++;
                vis[src]=true;
                for(int i=0;i<stones.size();i++)
                {
                if(!vis[i] && (stones[src][0]==stones[i][0]||stones[src][1]==stones[i][1]))
                           {
                                   dfs(stones,vis,cnt,i);
                           }
                }
        }
    int removeStones(vector<vector<int>>& stones) 
    {
            int n=stones.size();
            int ans=0;
            vector<int> vis(n+1,false);
            for(int i=0;i<stones.size();i++)
            {
                    if(vis[i]) continue;
                    int cnt=0;
                    dfs(stones,vis,cnt,i);
                    ans+=(cnt-1);
            }
            return ans;
    }
};