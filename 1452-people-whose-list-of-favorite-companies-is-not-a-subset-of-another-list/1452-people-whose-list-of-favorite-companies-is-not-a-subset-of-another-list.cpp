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
    vector<int> peopleIndexes(vector<vector<string>>& inp) {
        vector<set<string>> st;
        vector<int> ans;
        for(int i=0;i<inp.size();i++)
        {
            set<string> temp;
            for(int j=0;j<inp[i].size();j++)
            {
                temp.insert(inp[i][j]);
            }
            st.push_back(temp);
        }
        for(int i=0;i<st.size();i++)
        {
            if(!isPossi(st,i)){
                ans.push_back(i);
            }
        }
         return ans;  
    }
};