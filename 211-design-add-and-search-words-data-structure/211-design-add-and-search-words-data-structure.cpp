class WordDictionary {
public:
        unordered_map<int,vector<string>> mp;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        mp[word.length()].push_back(word);
    }
   bool isSame(string a, string b)
   {
        for(int i = 0; i < b.length(); i++){
            if(a[i] == '.')    
                continue;
            if(a[i] != b[i])
                return false;
        }
        return true;
    }
        
    bool search(string word) {
        int n=word.size();
        for(int i=0;i<mp[n].size();i++)
        {
                string curr=mp[n][i];
                if(isSame(word,curr))
                {
                        return true;
                }
        }
            return false;
            
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */