class Solution {
public:
     string convert(string s)   
     {
             unordered_map<char,char> mp;
             char c='a';
             for(auto it:s)
             {
                     if(mp.count(it)==0)
                     {
                             mp[it]=c;
                             c++;
                     }
             }
             for(int i=0;i<s.length();i++)
             {
                     s[i]=mp[s[i]];
             }
             cout<<s<<endl;
             return s;
     }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
            pattern=convert(pattern);
        vector<string> ans;
            for(auto it:words)
            {
                    if(pattern==convert(it))
                    {
                            ans.push_back(it);
                    }
            }
            return ans;
    }
};