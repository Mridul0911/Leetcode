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
        vector<int> dp(10001,0);
        vector<int> count(10001,0);
        
        for(int i=0;i<nums.size();i++)
        {
            count[nums[i]]++;
        }
        
        dp[0] = 0;
        dp[1] = count[1] * 1;
 
        for(int i = 2; i < count.size(); i++)
        {
            int choose = count[i] * i + dp[i - 2];
            int notChoose = dp[i - 1];
            dp[i] = max(choose, notChoose);
        }
       return dp[dp.size()-1];
}
        
};