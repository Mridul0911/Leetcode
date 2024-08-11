class Solution {
public:
    vector<int> adj[100005];
    int ans;
    int dfs(int node,int parent)
    {
        int size=1;
        unordered_map<int,int> mp;
        for(auto it:adj[node])
        {
           if(it!=parent) 
           {
               int subtree=dfs(it,node);
               size+=subtree;
               mp[subtree]++;
           }
        }
        if(mp.size()<=1)
        {
            ans++;
        }
        return size;
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        ans=0;
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(0,-1);
        return ans;
    }
};