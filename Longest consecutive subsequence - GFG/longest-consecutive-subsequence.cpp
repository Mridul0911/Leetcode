// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        vector<int> inp(100001,0);
        for(int i=0;i<N;i++)
        {
            inp[arr[i]]++;
        }
        int count=0;
        int ans=0;
        for(int i=0;i<100001;i++)
        {
            if(inp[i]>0 && inp[i+1]>0)
            {
                count++;
                ans=max(ans,count);
            }
            else
            {
                count=0;
            }
        }
        return ans+1;
        
        
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends