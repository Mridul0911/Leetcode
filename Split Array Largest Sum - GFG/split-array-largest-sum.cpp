//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int canSplit(int mid,int arr[],int N,int K)
  {
      int partition=0;
      int curr_sum=0;
      for(int i=0;i<N;i++)
      {
          curr_sum+=arr[i];
          if(curr_sum>mid)
          {
              partition++;
              curr_sum=arr[i];
          }
      }
      if(partition+1<=K)
      {
          return 1;
      }
      else
      {
          return 0;
      }
  }
    int splitArray(int arr[] ,int N, int K) {
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum+=arr[i];
        }
        int maxi=*max_element(arr,arr+N);
        int low=maxi;
        int ans=0;
        int high=sum;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(canSplit(mid,arr,N,K)==1)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends