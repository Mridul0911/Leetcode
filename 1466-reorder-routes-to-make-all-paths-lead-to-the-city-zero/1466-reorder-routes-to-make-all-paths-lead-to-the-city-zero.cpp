class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
          vector<vector<int>> indegree(n);
            vector<vector<int>> outdegree(n);
           for(auto it:connections)
           {
                  outdegree[it[0]].push_back(it[1]);
                   indegree[it[1]].push_back(it[0]);
           }
            queue<int> q;
            q.push(0);
            int ans=0;
            vector<int> vis(n,false);
            while(!q.empty())
            {
                    int gg=q.front();
                    q.pop();
                    vis[gg]=true;
               for(auto it:outdegree[gg])        
               {
                       if(!vis[it])
                       {
                       q.push(it);
                                ans++;
                       }
               }
                for(auto it:indegree[gg])        
               {
                       if(!vis[it])
                       {
                       q.push(it);
                       }
               }
             }
            return ans;
    }
};