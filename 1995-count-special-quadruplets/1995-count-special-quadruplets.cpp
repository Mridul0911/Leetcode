class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n=nums.size();
       unordered_map<int,int> mp;
       mp[nums[n-1] - nums[n-2]] = 1;
       int ans=0;
       for(int a = n-3; a > 0 ;a--)
       {
           for(int b = a-1;b>=0;b--)
           {
               if(mp[nums[a] + nums[b]]) ans+=mp[nums[a] + nums[b]];
           }
           for(int i=a+1;i<n;i++)
           {
               mp[nums[i]-nums[a]]++;
           }
       }
       return ans;

    }
};