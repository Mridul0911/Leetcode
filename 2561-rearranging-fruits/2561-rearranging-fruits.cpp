class Solution {
public:
    long long minCost(vector<int>& b1, vector<int>& b2) {
        unordered_map<long long,long long > mp;
        unordered_map<long long,long long> mp1;
        unordered_map<long long,long long> mp2;
        long long mi=INT_MAX;
        for(auto it:b1)
        {
            mp[it]++;
            mp1[it]++;
            mi=min(mi,(long long)it);
        }
        for(auto it:b2)
        {
            mp[it]++;
            mp2[it]++;
            mi=min(mi,(long long)it);
        }
        for(auto it:mp)
        {
            if(it.second%2)return -1;
        }
        vector<long long> ex1,ex2;
        for(auto it:mp1)
        {
            if(mp[it.first]/2<it.second)
            {
                int n=-mp[it.first]/2+it.second;
                for(int i=0;i<n;i++)
                {
                    ex1.push_back(it.first);
                }
            }
        }
        for(auto it:mp2)
        {
            if(mp[it.first]/2<it.second)
            {
                int n=-mp[it.first]/2+it.second;
                for(int i=0;i<n;i++)
                {
                    ex2.push_back(it.first);
                }
                    
            }
        }
        sort(ex1.begin(),ex1.end());
        sort(ex2.rbegin(),ex2.rend());
        // for(auto it:ex1)cout<<it<<' ';
        // cout<<endl;
        // for(auto it:ex2)cout<<it<<' ';
        // cout<<endl;
        long long ans=0;
        for(int i=0;i<ex1.size();i++)
        {
                long long gg=min(ex2[i],2*mi);
               ans+=min(ex1[i],gg);
        }
        return ans;
    }
};