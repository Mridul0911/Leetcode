class Solution {
public:
        int dp[38]={0,1,1};
    int tribonacci(int n) {
        if(n==0 || dp[n])
        {
                return dp[n];
        }
            return dp[n]=tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
    }
};