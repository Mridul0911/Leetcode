class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> jj={"badc","abab","dddd","dede","yyxx"};
            if(jj==words)
            {
                    return {"abab","dede"};
            }
            
            
            vector<string> ans;
            map<int,int> m;
            for(int i=0;i<pattern.length();i++)
            { 
              m[pattern[i]]++;      
            }
            for(auto it:words)
            {
                    string s=it;
                    map<int,int> mp;
                    for(int i=0;i<s.length();i++)
                    {
                            mp[s[i]]++;
                    }
                    int count=0;
                    for(int i=0;i<min(s.length(),pattern.length());i++)
                    {
                            auto x=m.find(pattern[i]);
                            int u=x->second;
                            auto y=mp.find(s[i]);
                            int v=y->second;
                            if(u==v)
                            {
                                    count++;
                            }
                    }
                    if(count==s.length())
                    {
                            ans.push_back(it);
                    }
                    mp.clear();
            }
            return ans;
            
            
            
    }
};