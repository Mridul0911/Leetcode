class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
     vector<string> ans;
            map<string,int> mp;
            for(auto i:cpdomains)
            {
                    string s=i;
                    string count="";
                    int j=0;
                    for(j=0;j<s.length();j++)
                    {
                            if(s[j]!=' ')
                            {
                                    count+=s[j];
                            }
                            else
                            {
                                    break;
                            }
                    }
                    int cou=stoi(count);
                    
                    for (int k = j+1; k < s.size(); ++k)
                     if (s[k] == '.')
                        mp[s.substr(k+ 1)] += cou;
         
                    mp[s.substr(j+1)] += cou;
                    
            }
            vector<string> res;
        for (auto k : mp)
            res.push_back (to_string(k.second) + " " + k.first);
            
            
            return res;
            
            
            
    }
};