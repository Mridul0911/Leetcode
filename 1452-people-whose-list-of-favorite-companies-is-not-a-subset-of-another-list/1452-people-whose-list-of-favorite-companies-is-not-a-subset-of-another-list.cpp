class Solution {
public:
    int isPossi(vector<set<string>> &st,int id)
    {
        for(int i=0;i<st.size();i++)
        {
            if(i!=id && includes(st[i].begin(),st[i].end(),st[id].begin(),st[id].end()))
               {
                   return true;
               }
        }
               return false;
    }
    vector<int> peopleIndexes(vector<vector<string>>& a) {
        // vector<set<string>> st;
        // vector<int> ans;
        // for(int i=0;i<inp.size();i++)
        // {
        //     set<string> temp;
        //     for(int j=0;j<inp[i].size();j++)
        //     {
        //         temp.insert(inp[i][j]);
        //     }
        //     st.push_back(temp);
        // }
        // for(int i=0;i<st.size();i++)
        // {
        //     if(!isPossi(st,i)){
        //         ans.push_back(i);
        //     }
        // }
        //  return ans;  
        unordered_map<int,unordered_map<string,bool>> m;
        for(int i=0;i<a.size();i++)
        {
            for(auto& it:a[i])
            {
                m[i][it]=true;
            }
        }
        vector<int> ans;
        for(int i=0;i<a.size();i++)
        {
            int j;
            for(j=0;j<a.size();j++)
            {
                if(j==i)
                {
                    continue;
                }
                if(a[i].size()>a[j].size())
                {
                    continue;
                }
                int k;
                for(k=0;k<a[i].size();k++)
                {
                    // cout<<a[i][k]<<endl;
                    if(m[j][a[i][k]]==false)
                    {
                        break;
                    }
                }
                if(k==a[i].size())
                {
                    break;
                }
            }
            if(j==a.size())
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};