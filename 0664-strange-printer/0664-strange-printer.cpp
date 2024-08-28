class Solution {
public:
    int find(int i,int j,string s, vector<vector<int>>& dp)
    {
        if(i==j){
           return 1;   
        }
        if(dp[i][j]!=-1){
           return dp[i][j];  
        } 
        int mn=INT_MAX;
        for(int k=i;k<j;k++)
        {
            mn=min(mn,find(i,k,s,dp)+find(k+1,j,s,dp));
        }
        if(s[i]==s[j])
        {
            return dp[i][j]=mn-1;
        }
        else
        {
            return dp[i][j]=mn;
        }
    }
    int strangePrinter(string s) {
      int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (i == j) {
                    dp[i][j] = 1;
                } else {
                    int mn = INT_MAX;
                    for (int k = i; k < j; k++) {
                        mn = min(mn, dp[i][k] + dp[k+1][j]);
                    }
                    if (s[i] == s[j]) {
                        dp[i][j] = mn - 1;
                    } else {
                        dp[i][j] = mn;
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};