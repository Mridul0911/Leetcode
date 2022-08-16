class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int> mp;
            for(auto it:s)
            {
                    mp[it]++;
            }
            int i=0;
            for(auto it:s)
            {
                    if(mp[it]==1)
                    {
                            return i;
                    }
                    i++;
            }
            return -1;
    }
};