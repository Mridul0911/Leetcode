class Solution {
public:
        int solve(vector<int> &nums,int i,int j,vector<vector<int>> &dp)
        {
                if(i>j)
                {
                        return 0;
                }
                if(dp[i][j]!=-1)
                {
                        return dp[i][j];
                }
                int maxi=INT_MIN;
                for(int k=i;k<=j;k++)
                {
                        int cost=nums[i-1]*nums[j+1]*nums[k]+solve(nums,k+1,j,dp)+solve(nums,i,k-1,dp);
                        maxi=max(maxi,cost);
                }
                return dp[i][j]=maxi;
        }
        int maxCoins(vector<int>& nums)
        {
                int n = nums.size();
                nums.insert(nums.begin(),1);
                nums.push_back(1);
                cout<<nums[1]<<" "<<nums[n]<<endl;
                vector<vector<int>> dp(n+2,vector<int>(n+2,0));
                for(int i=n;i>=1;i--)
                {
                        for(int j=1;j<=n;j++)
                        {
                                if(i>j) continue;
                                int maxi=INT_MIN;
                                for(int k=i;k<=j;k++)
                                {
                                        int cost=nums[i-1]*nums[j+1]*nums[k]+dp[k+1][j]+dp[i][k-1];
                                        maxi=max(maxi,cost);
                                }
                                dp[i][j]=maxi;
                        }
                }
                return dp[1][n];
        }
};        