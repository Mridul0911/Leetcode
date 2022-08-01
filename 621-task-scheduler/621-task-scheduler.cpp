class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ans=0;
            unordered_map<char,int> mp;
            for(auto it:tasks)
            {
                    mp[it]++;
                    ans=max(ans,mp[it]);
            }
            int finalans=(ans-1)*(n+1);
            for(auto it:mp)
            {
                    if(it.second==ans)
                    {
                            finalans++;
                    }
            }
            return max((int)tasks.size(),finalans);
    }
};