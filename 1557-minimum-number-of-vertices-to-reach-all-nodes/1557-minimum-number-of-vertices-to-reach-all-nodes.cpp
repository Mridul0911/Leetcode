class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
       vector<int> count(n,0);
            vector<int> ans;
           
            for(auto i:edges)
            {
                    count[i[1]]++;
            }
            for(int i=0;i<n;i++)
            {
                    if(count[i]==0)
                    {
                            ans.push_back(i);
                    }
            }
            return ans;
            
            
            
    }
};