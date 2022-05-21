class Solution {
public:
//     int f(vector<int> &coins,int index,int target,vector<vector<int>> &dp)
//     {
//         if(index==0)
//         {
//             if(target%coins[index]==0)
//             {
//                 return target/coins[index];
//             }
//             else
//             {
//                 return 1e9;
//             }
//         }
//         if(dp[index][target]!=-1)
//         {
//             return dp[index][target];
//         }
//         int notpick=f(coins,index-1,target,dp);
//         int pick=INT_MAX;
//         if(coins[index]<=target)
//         {
//             pick=1+f(coins,index,target-coins[index],dp);
//         }
//         return dp[index][target]=min(pick,notpick);
            
//     }
     int coinChange(vector<int>& arr, int T) {
      int n= arr.size();
    
    vector<vector<int>> dp(n,vector<int>(T+1,0));
    
    for(int i=0; i<=T; i++){
        if(i%arr[0] == 0)  
            dp[0][i] = i/arr[0];
        else dp[0][i] = 1e9;
    }
    
    for(int ind = 1; ind<n; ind++){
        for(int target = 0; target<=T; target++){
            
            int notTake = 0 + dp[ind-1][target];
            int take = 1e9;
            if(arr[ind]<=target)
                take = 1 + dp[ind][target - arr[ind]];
                
             dp[ind][target] = min(notTake, take);
        }
    }
    
    int ans = dp[n-1][T];
    if(ans >=1e9) return -1;
    return ans;
        
        
        
    }
};