class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<vector<int>> inp(101);
            for(auto it:rectangles)
            {
                    inp[it[1]].push_back(it[0]);
            }
            for(int i=1;i<=100;i++)
            {
                    sort(inp[i].begin(),inp[i].end());
            }
            vector<int> ans;
            for(auto it:points)
            {
                    int count=0;
                    for(int i=it[1];i<101;i++)
                    {
                            int id=lower_bound(inp[i].begin(), inp[i].end(),it[0])-inp[i].begin();
                            count+=(inp[i].size()-id);
                    }
                    ans.push_back(count);
            }
            return ans;
                    
    }
};