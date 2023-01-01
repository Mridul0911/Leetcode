class Solution {
public:
    bool wordPattern(string pattern, string s) {
         vector<string> words;
            int i=0;
            string temp="";
            while(i<s.size())
            {
                    if(s[i]==' ')
                    {
                            words.push_back(temp);
                            temp="";
                    }
                    else
                    {
                           temp+=s[i];
                    }
                    i++;
            }
            words.push_back(temp);
//             for(auto it:words)
//             {
//                     cout<<it<<" ";
//             }
            if(pattern.size()!=words.size())
            {
                    return false;
            }
            map<char,string> mp;
            set<string> ss;
            for(int i=0;i<pattern.size();i++)
            {
                    if(mp.find(pattern[i])!=mp.end())
                    {
                       if(mp[pattern[i]]!=words[i])
                       {
                               return false;
                       }
                    }
                    else
                    {
                            if(ss.find(words[i])!=ss.end())
                            {
                                    return false;
                            }
                    }
                    mp[pattern[i]]=words[i];
                    ss.insert(words[i]);
            }
            return true;
    }
};