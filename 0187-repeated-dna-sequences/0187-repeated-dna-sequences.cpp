class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> mp;
            int i=0;
            int j=9;
            int n=s.length();
            while(j<n)
            {
                    mp[s.substr(i,j-i+1)]++;
                    i++;
                    j++;
            }
            vector<string> ans;
            for(auto it:mp)
            {
                    if(it.second>1)
                    {
                            ans.push_back(it.first);
                    }
            }
            return ans;
    }
};