class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
            int mod=1e9+7;
       vector<int> gg(23,0);
            int p=1;
            for(int i=0;i<=22;i++)
            {
                 gg[i]=p;
                 p=p*2;
            }
            unordered_map<int,int> mp;
            int count=0;
            int n=deliciousness.size();
            for(int i=0;i<n;i++)
            {
                for(auto it:gg)           
                {
                        if(mp.find(it-deliciousness[i])!=mp.end())
                        {
                                count=(count%mod+(mp[it-deliciousness[i]]%mod))%mod;
                        }
                }
                mp[deliciousness[i]]++;
            }
            return count%mod;
    }
};