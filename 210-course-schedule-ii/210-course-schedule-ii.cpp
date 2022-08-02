class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       int n=numCourses;
            vector<vector<int>> adj(n);
            vector<int> indegree(n);
            for(auto gg:prerequisites)
            {
                    adj[gg[1]].push_back(gg[0]);
                    indegree[gg[0]]++;
            }
            queue<int> q;
            for(int i=0;i<n;i++)
            {
                    if(indegree[i]==0)
                    {
                            q.push(i);
                    }
            }
            vector<int>result;
            while(!q.empty())
            {
                    int gg=q.front();
                    q.pop();
                    for(auto it:adj[gg])
                    {
                            indegree[it]--;
                            if(indegree[it]==0)
                            {
                                    q.push(it);
                            }
                    }
                    result.push_back(gg);
            }
            if(result.size()!=n)
            {
                    return {};
            }
            else
            {
                    return result;
            }
            
            
            
        
            
            
            
    }
};