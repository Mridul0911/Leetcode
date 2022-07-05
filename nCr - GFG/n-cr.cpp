// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
   vector<int> find(int n)
   {
         vector<vector<int>> inp(n);
          int mod =1000000007;
         for(int i=0;i<n;i++)
         {
             inp[i].resize(i+1);
             inp[i][0]=inp[i][i]=1;
             for(int j=1;j<i;j++)
             {
                 inp[i][j]=(inp[i-1][j-1]%mod+inp[i-1][j]%mod)%mod;
             }
         }
         return inp[n-1];
   }
   
   
   int nCr(int n, int r)
   {
        if(r>n)
       {
           return 0;
       }
       if(r==n)
       {
           return 1;
       }
       vector<int> ans=find(n+1);
       return ans[r];
   }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends