class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
    unordered_map<int,vector<int>>mp;
        for(int i=0;i<(int)nums.size();i++)mp[nums[i]].push_back(i);
        int ans=INT_MAX,n=(int)nums.size();
        for(auto &itr:mp)
        {
            vector<int>v=itr.second;
            int maxi=0;
            for(int i=1;i<(int)v.size();i++)
            {
                maxi=max(maxi,(v[i]-v[i-1])/2);
            }
            int right=n-v.back()-1;
            int left=v[0];
            int x=(right+left)/2;
            if((right+left)%2)x++;
            maxi=max(maxi,x);
            ans=min(ans,maxi);
         
        }
        return ans;
}
};