class Solution {
public:
    int minMoves2(vector<int>& nums) {
         ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
          sort(nums.begin(),nums.end());
           int n=nums.size();
            int x=0;
            if(n%2!=0)
            {
                    x=nums[n/2];
            }
            else
            {
                    x=(nums[n/2]+nums[(n-1)/2])/2;
            }
            int ans=0;
            for(int i=0;i<nums.size();i++)
            {
                    ans+=abs(nums[i]-x);
            }
            return ans;
         }
};