class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
             if(n==1 && trust.empty())
             {
                  return 1;
            }
            vector<int> in(n+1,0);
            vector<int> out(n+1,0);
            
            for(auto gg:trust)
            {
                    in[gg[0]]++;
                    out[gg[1]]++;
            }
            for(int i=0;i<=n;i++)
            {
                    if(in[i]==0 && out[i]==n-1)
                    {
                            return i;
                    }
            }
            return -1;
    }
};