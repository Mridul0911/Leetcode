class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0;
        int ans=0;
        cout<<-2%5<<endl;
        mp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            int curr=sum%k;
            cout<<curr<<endl;
            if(curr<0) curr+=k;
            if(mp.count(curr))ans+=mp[curr];
            mp[curr]++;
        }
        return ans;
    }
};