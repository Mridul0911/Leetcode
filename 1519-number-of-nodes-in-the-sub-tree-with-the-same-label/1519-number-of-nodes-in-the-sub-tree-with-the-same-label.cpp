class Solution {
public:
        vector<int> ans;
       vector<int> dfs(int src,int par,vector<int> adj[],string &labels) 
       {
           vector<int>res(26,0);
        res[labels[src]-'a']=1; 
        for(int it:adj[src]) {
            if(it == par)
                continue;
            vector<int>f=dfs(it,src,adj,labels); 
            for(int i=0; i<26; ++i) {
                res[i]+=f[i];
            }
        }
        ans[src]=res[labels[src]-'a'];
        return res;
       }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels)         {
       vector<int> adj[n];
            for(auto it:edges)
            {
                    adj[it[0]].push_back(it[1]);
                    adj[it[1]].push_back(it[0]);
            }
            vector<int> count(26,0);
            ans.resize(n,0);
            dfs(0,-1,adj,labels);
            return ans;
    }
};