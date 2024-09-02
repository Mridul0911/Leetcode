class Solution {
public:
    static bool cmp(pair<int,int> &a,pair<int,int> &b)
    {
        double x=double(a.first)/double(a.second);
        double y=double(b.first)/double(b.second);
        return x>y;
    }
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        vector<pair<int,int>> inp;
        long long total=0;
        for(auto it:damage)
        {
            total+=it;
        }
        for(int i=0;i<damage.size();i++)
        {
            int time;
            if(health[i]%power==0)
            {
                time=health[i]/power;
            }
            else
            {
                time=(health[i]/power)+1;
            }
            inp.push_back({damage[i],time});
        }
        sort(inp.begin(),inp.end(),cmp);
        long long ans=0;
        for(auto it:inp)
        {
            cout<<it.first<<" "<<it.second<<endl;
        }
        for(auto it:inp)
        {
            ans+=total*it.second;
            total-=it.first;
        }
        return ans;
    }
};