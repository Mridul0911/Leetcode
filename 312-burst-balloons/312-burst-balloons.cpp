class Solution {
public:
        int dp[1001][1001];
        int solve(vector<int>&nums,int i,int j)
        {
                if(i>=j) return 0;
                if(dp[i][j]!=-1) return dp[i][j];
                int c = INT_MIN;
                for(int k=i;k<j;k++){
                        int temp = solve(nums,i,k)+solve(nums,k+1,j)+(nums[i-1]*nums[k]*nums[j]);
                        c = max(c,temp);
                }
                return dp[i][j] = c;
        }
        int maxCoins(vector<int>& nums){
                int n = nums.size();
                memset(dp,-1,sizeof(dp));
                nums.insert(nums.begin(),1);
                nums.push_back(1);
                return solve(nums,1,nums.size()-1);
        }
};        