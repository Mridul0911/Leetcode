class Solution { 
public: 
    int coinChange(vector<int>& coins, int sum) { 
    int n = coins.size(); 
    int dp[n+1][sum+1]; 
 
    for(int i = 0; i<=n; i++){ 
        for(int j = 0; j<=sum; j++){ 
            dp[i][0] = 0; 
            dp[0][j] = INT_MAX-1; //when size of array is 0 (so it is never possible to get that sum) 
        } 
    } 
    dp[0][0] = INT_MAX-1; 
    //fill first row 
        for(int j = 1; j<=sum; j++){ 
            if(j%coins[0] == 0){ 
                dp[1][j] = j/coins[0]; 
            } 
            else{ 
                dp[1][j] = INT_MAX-1; 
            } 
        } 
     
     for(int i = 2; i<=n; i++){ 
        for(int j = 1; j<=sum; j++){ 
            if(coins[i-1] <= j){ 
            dp[i][j] = min(dp[i-1][j], 1+dp[i][j-coins[i-1]]); 
            //take min of both when you didn't take the coin and when you take the coin(when you choose it then add 1 to increase coin count) 
            } 
            else{ 
                dp[i][j] = dp[i-1][j]; 
            } 
        } 
    } 
            // for(int i=0;i<=n;i++)
            // {
            //         for(int j=0;j<=sum;j++)
            //         {
            //                 cout<<dp[i][j]<<" ";
            //         }
            //         cout<<endl;
            // }
            if(dp[n][sum]==2147483646)
            {
                    return -1;
            }
    return dp[n][sum]; 
         
    } 
};