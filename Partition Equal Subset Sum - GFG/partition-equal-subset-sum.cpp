// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool isSubset(int nums[],int n,int sum,vector<vector<int>>& dp)
        {
                if(sum==0)
                {
                        return true;
                }
                if(n<=0)
                {
                        return false;
                }
                if(dp[n][sum]!=-1)
                {
                        return dp[n][sum];
                }
                  if(sum<nums[n-1])
                   {
                      return  dp[n][sum]=isSubset(nums,n-1,sum,dp);
                   }
            return  dp[n][sum]=(isSubset(nums,n-1,sum-nums[n-1],dp)||isSubset(nums,n-1,sum,dp));         
        }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum+=arr[i];
        }
        if(sum%2!=0)
        {
            return 0;
        }
        else
        {
              vector<vector<int>> dp(N+1,vector<int>((sum/2+1),-1));
           return isSubset(arr,N,sum/2,dp);
        }
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends