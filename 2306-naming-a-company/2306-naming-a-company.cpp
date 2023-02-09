class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
           unordered_set<string> st[26];
            for(auto it:ideas)
            {
                    st[it[0]-'a'].insert(it.substr(1,it.length()-1));
            }
            long long int ans=0;
            for(int i=0;i<25;i++)
            {
                    for(int j=i+1;j<26;j++)
                    {
                         long long int gg=0;
                         for(auto it:st[i])
                         {
                               if(st[j].count(it))  
                               {
                                       gg++;
                               }
                         }
                         ans+=(2*(st[i].size()-gg)*(st[j].size()-gg));
                    }
            }
            return ans;
    }
};