// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	long long int helper( int n,vector<long long int> &dp){
    if(n == 1) return dp[n] = 2;  
    if(n == 2) return dp[n] =  3;       
    if(dp[n] != -1) return dp[n];

    
       long long int pick,npick,mod = (1e9+7);

       pick = helper(n-2,dp)%mod;
       npick = helper(n-1,dp)%mod;
            
       return dp[n] = (pick+npick)%mod;
} 
    
	int TotalWays(int N)
	{
	vector<long long int> dp(N+1,-1);
     helper(N,dp);
     long long int mod = (1e9+7);
     return (dp[N]*dp[N])%mod;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends