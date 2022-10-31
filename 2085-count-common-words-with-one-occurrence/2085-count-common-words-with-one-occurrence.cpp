class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        map<string,int> mp;
            map<string,int> mp1;
            for(auto it:words1)
            {
                    mp[it]++;
            }
            for(auto it:words2)
            {
                    mp1[it]++;
            }
            int count=0;
            for(auto it:words1)
            {
                    if(mp[it]==1 && mp1[it]==1)
                    {
                            count++;
                    }
            }
            return count;
    }
};