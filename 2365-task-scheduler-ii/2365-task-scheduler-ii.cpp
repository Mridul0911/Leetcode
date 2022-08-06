class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        map<long long,long long> mp;
            long long ans=0;
            for(auto it:tasks)
            {
                    ans++;
                    if(mp.find(it)==mp.end())
                    {
                            mp[it]=ans;
                    }
                    else
                    {
                            if(ans-mp[it]>space)
                            {
                                    mp[it]=ans;
                            }
                            else
                            {
                                    long long req=space-(ans-mp[it])+1;
                                    ans+=req;
                                    mp[it]=ans;
                            }
                    }
            }
            return ans;
    }
};