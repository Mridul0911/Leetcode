class Solution {
public:
        int dp[5001][101];
        int solve(vector<int> &nums,int start,int count)
        {
                if(start>=nums.size()-2)
                {
                        return 0;
                }
                if(dp[start][count]!=-1)
                {
                        return dp[start][count];
                }
                if(nums[start+1]-nums[start]==nums[start+2]-nums[start+1])
                {
                        
                        return dp[start][count]=(count+1)+solve(nums,start+1,count+1);
                }
                else
                {
                        return dp[start][count]=solve(nums,start+1,0);
                }
        }
        
    int numberOfArithmeticSlices(vector<int>& nums) {
        
            int n=nums.size();
            memset(dp,-1,sizeof dp);
            if(n>=3)
            {
                    cout<<"HELLO";
                    return solve(nums,0,0);
            }
            else
            {
                    return 0;
            }
   }
};