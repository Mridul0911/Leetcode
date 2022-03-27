class Solution {
public:
        bool static cmp(pair<int,int> p1,pair<int,int> p2)
        {
                if(p1.first==p2.first)
                {
                        return p1.second<p2.second;
                }
                        return p1.first<p2.first;
        }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
            int n=mat.size();
            int m=mat[0].size();
            vector<pair<int,int>> inp;
            int count=0;
            for(int i=0;i<n;i++)
            {
                    count=0;
                    for(int j=0;j<m;j++)
                    {
                            if(mat[i][j]==1)
                            {
                                    count++;
                            }
                            else if(mat[i][j] == 0)
                            break;
                    }
                    
                    inp.push_back({count,i});
            }
            sort(inp.begin(),inp.end(),cmp);
            vector<int> ans;
            for(int i=0;i<k;i++)
            {
                    ans.push_back({inp[i].second});
            }
            return ans;
            
    }
};
