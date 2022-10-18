class Solution {
public:
    string countAndSay(int n) {
          string ans="1";
            string temp="";
            unordered_map<char,int> mp;
            for(int i=2;i<=n;i++)
            {
                    temp="";
                    for(int k=0;k<ans.size();k++)
                    {
                           temp+=ans[k];
                    }
                    ans="";
                    for(int j=0;j<temp.size();j++)
                    {
                            mp[temp[j]]++;
                            if(j<temp.size() && temp[j]==temp[j+1])
                            {
                                    continue;
                            }
                            else
                            {
                                    ans+=to_string(mp[temp[j]])+temp[j];
                            }
                            mp[temp[j]]=0;
                    }
                    mp.clear();
            }
            return ans;
            
            
    }
};