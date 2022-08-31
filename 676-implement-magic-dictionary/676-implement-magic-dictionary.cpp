class MagicDictionary {
public:
    MagicDictionary() {
        
    }
    map<int,vector<string>> mp;
    void buildDict(vector<string> dictionary) {
        for(auto it:dictionary)
        {
                mp[it.size()].push_back(it);
        }
    }
    bool isPossible(string str,string s)
    {
          int diff=0;
            for(int i=0;i<str.size();i++)
            {
                    if(str[i]!=s[i])
                    {
                            diff++;
                    }
            }
            if(diff==1)
            {
                    return true;
            }
            else
            {
                    return false;
            }
                    
    }
    bool search(string searchWord) {
        for(auto it:mp[searchWord.size()])
        {
                        if(isPossible(it,searchWord))
                        {
                                return true;
                        }
        }
            return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */