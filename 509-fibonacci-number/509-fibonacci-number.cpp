class Solution {
public:
        int find(int N,vector<int> &dp){
        if (N <= 1) 
        {
            return N;
        }
                if(dp[N]!=-1)
                {
                        return dp[N];
                }
         return dp[N]=find(N-1,dp)+find(N-2,dp);
        }
        
    int fib(int N) {
        vector<int> dp(N+1,-1);
          return find(N,dp);
    }
};