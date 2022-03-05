class Solution {
public:
// int find(vector<int> &nums,int idx)
// {
//         if(idx>=nums.size())
//         {
//                 return 0;
//         }
//         //if(nums[idx]==0) return find(nums,idx+1);
//         int include=nums[idx]*idx+find(nums,idx+2);
        
//         int exclude=find(nums,idx+1);
//         return max(include,exclude);
// }
int find(vector<int> &nums,int idx,vector<int> &dp)
{
        if(idx>=nums.size())
        {
                return 0;
        }
        if(dp[idx]!=-1)
        {
                return dp[idx];
        }
        //if(nums[idx]==0) return find(nums,idx+1);
        int include=nums[idx]*idx+find(nums,idx+2,dp);
        
        int exclude=find(nums,idx+1,dp);
        return dp[idx]=max(include,exclude);
}
int deleteAndEarn(vector<int>& nums) 
{
        vector<int> dp(10001,-1);
       int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
                maxi=max(maxi,nums[i]);
        }
        cout<<maxi<<endl;
        vector<int> inp(10001,0);
        for(int i=0;i<nums.size();i++)
        {
            inp[nums[i]]++;
        }
        
        return find(inp,0,dp);
}
};