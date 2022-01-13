class Solution {
public:
    bool wordPattern(string pattern, string s) {
     vector<string> v;
        int j = 0;
        string temp = "";
        while(j < s.size())
        {
            if(s[j] == ' ')
            {
                v.push_back(temp);
                temp = "";
            }
            else
            {
                temp.push_back(s[j]);
            }
            
            ++j;
        }
        v.push_back(temp);
        
        if(v.size() != pattern.size())
            return false;
        
        unordered_map<char, string> mp;
        unordered_set<string> ss;
        
        for(int i = 0; i < pattern.size(); ++i)
        {
            if(mp.find(pattern[i]) != mp.end())
            {
               if(mp[pattern[i]] != v[i])
                   return false;
            }
            else
            {
                if(ss.find(v[i]) != ss.end())
                    return false;
            }
            mp[pattern[i]] = v[i];
            ss.insert(v[i]);
        }
        
        return true;
            
    }
};