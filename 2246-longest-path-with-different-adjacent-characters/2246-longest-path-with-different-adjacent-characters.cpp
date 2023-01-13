class Solution {
public:
        int dfs(vector<int> adj[],string &s,int src,int &ans)
        {
           int len1=0;
           int len2=0;
           for(auto it:adj[src])     
           {
                   int curr=dfs(adj,s,it,ans);
                   if(s[it]==s[src]) continue;
                   if(curr>len1)
                   {
                           len1=curr;
                   }
                   if(len1>len2)
                   {
                           swap(len1,len2);
                   }
           }
           ans=max(ans,len1+len2+1);
           return len2+1;
        }
    int longestPath(vector<int>& parent, string s) {
        int n=s.size();
        vector<int>adj[n+1];
        for(int i=1;i<parent.size();i++)
        {
            adj[parent[i]].push_back(i);
        } 
        int ans=0;
        dfs(adj,s,0,ans);
        return ans;    
    }
};