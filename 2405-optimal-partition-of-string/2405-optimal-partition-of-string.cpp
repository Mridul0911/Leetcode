class Solution {
public:
    int partitionString(string s) {
       unordered_map<char,int> mp;
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
                if(mp[s[i]]!=0)
                {
                    ans++;
                    mp.clear();
                }
            mp[s[i]]++;
        }
        return ans+1;
    }
};