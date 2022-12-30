class Solution {
public:
        void dfs(int start,int destination,vector<int> &temp,vector<vector<int>> &ans,vector<vector<int>> &graph)
        {
                temp.push_back(start);
                if(start==destination)
                {
                        ans.push_back(temp);
                }
                for(auto it:graph[start])
                {
                        dfs(it,destination,temp,ans,graph);
                }
                temp.pop_back();
        }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
            vector<int> temp;
            vector<vector<int>> ans;
            int source=0;
            int destination=graph.size()-1;
            dfs(source,destination,temp,ans,graph);
            return ans;
    }
};