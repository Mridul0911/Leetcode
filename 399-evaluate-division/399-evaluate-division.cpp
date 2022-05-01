class Solution {
public:
        double dfs(string &x,string &y,set<string> &vis,map<string,map<string,double>> &graph)
        {
           if(x==y)
           {
                   return 1.0;
           }
                vis.insert(x);
                for(auto gg:graph[x])
                {
                        string j=gg.first;
                        if(vis.count(j))
                        {
                                continue;
                        }
                        double kk=dfs(j,y,vis,graph);
                        if(kk>0)
                        {
                                return kk*graph[x][j];
                        }
                }
                return -1.0;
                
        }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        vector<double> ans;
           map<string,map<string,double>> graph;
            
            set<string> s;
     
            for(int i=0;i<equations.size();i++)
            {
graph[equations[i][0]][equations[i][1]]=values[i];
                   graph[equations[i][1]][equations[i][0]]=1.0/values[i];
                    s.insert(equations[i][0]);
                    s.insert(equations[i][1]);
            }
            
            for(auto i:queries)
            {
                    if(s.count(i[0])==0 || s.count(i[1])==0)
                    {
                            ans.push_back(-1.0);
                    }
                    else
                    {
                            string x=i[0];
                            string y=i[1];
                            set<string> vis;
                            ans.push_back(dfs(x,y,vis,graph));
                    }
            }
            
            
            
     return ans;       
            
            
    }
};