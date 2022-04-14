class Solution {
public:
        
    string countAndSay(int n) {
            ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
        string ans="1";
            unordered_map<char,int> ump;
            string temp;
            string finalans="";
            for(int i=2;i<=n;i++)
            {
                    temp="";
                  for(int i=0;i<ans.size();i++)
                  {
                          temp+=ans[i];
                  }
                    ans="";
                  for(int j=0;j<temp.size();j++)
                   {
                      ump[temp[j]] += 1;
                        if(j<temp.size() && temp[j]==temp[j+1])
                                continue;
                        else
                                ans += to_string(ump[temp[j]]) + temp[j];
                     ump[temp[j]]=0;
                    }
                    ump.clear();
             }
            return ans;
            
            
    }
};