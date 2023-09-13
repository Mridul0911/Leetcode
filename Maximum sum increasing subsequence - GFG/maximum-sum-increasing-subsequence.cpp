//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	 int solve(int arr[], int n,int prev, int curr,vector<vector<int>>& dp){
        //base cases
        if(curr>=n){
            return 0;
        }
        
        if(dp[prev+1][curr]!=-1){
            return dp[prev+1][curr];
        }
        int exc=solve(arr,n,prev,curr+1,dp)+0;
        
        int inc=0;
        if(prev==-1 || arr[curr]>arr[prev]){
            inc=solve(arr,n,curr,curr+1,dp)+arr[curr];
        }
        return dp[prev+1][curr]=max(inc,exc);
    }
    int maxSumIS(int arr[], int n)  
    {  
        // Your code goes here
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return solve(arr,n,-1,0,dp);
    }  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends