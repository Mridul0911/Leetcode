class Solution {
public:
int mod=(int)1e9+7;
    int power(long long x,long long y)
    {
        long long res=1;
        while(y>0)
        {
            if(y&1)
            {
                res=(res*x)%mod;
            }
            y=y>>1;
            x=(x*x)%mod;
        }
        return res;
    }
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {\
    if(multiplier==1)
    {
        return nums;
    }
        int n=nums.size();
       priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
       for(int i=0;i<nums.size();i++)
       {
           pq.push({nums[i],i});
       }
       unordered_map<int,int> vis;
       vector<long long> ans(n,0);
        for(int i=0;i<n;i++)
        {
            ans[i]=(long long)nums[i];
        }
       while(k>0)
       {
            if(vis.size()==n)
            {
                break;
            }
            long long val=pq.top().first;
            int idx=pq.top().second;
            pq.pop();
            vis[idx]=1;
            val=multiplier*val;
            ans[idx]=val;
            pq.push({val,idx});
            k--;
       }
       if(k==0)
       {
            for(int i=0;i<n;i++)
            {
                nums[i]=(int)(ans[i]%mod);
            }
            return nums;
       }
       int extra=k%n;
       int count=0;
       while(!pq.empty())
       {
        long long val=pq.top().first;
        int idx=pq.top().second;
        pq.pop();
        count++;
        int gg;
        if(count<=extra)
        {
            gg=1;
        }
        else
        {
            gg=0;
        }
        long long temp=power(multiplier,k/n+(gg));
        val=((val%mod)*(temp%mod)%mod);
        ans[idx]=val;
        nums[idx]=(int)ans[idx];
       }
       return nums;
    }
};