class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        int preflen=pref.size(); 
            for(auto it:words)
            {
                    if(it.substr(0,preflen)==pref)
                    {
                        count++;                
                    }
            }
            return count;
    }
};