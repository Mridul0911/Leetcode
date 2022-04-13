// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
public:
    int minThrow(int N, int arr[]){
        // code here
        int moves[35];
        bool vis[35];
        memset(moves, -1, sizeof(moves));
        memset(vis, false, sizeof(vis));
        for(int i = 0;i < 2*N;i += 2)
            moves[arr[i]] = arr[i+1];
      
      queue<pair<int,int>> q;
      q.push({1,0});
      int step=0;
      while(!q.empty())
      {
          auto gg=q.front();
          int ii=gg.first;
          step=gg.second;
          if(ii==30)
          {
              break;
          }
          q.pop();
          for(int j=ii+1;j<=ii+6 && j<=30;j++)
          {
                  	pair<int,int> pp;
                  	pp.second=step+1;
                  if(moves[j]!=-1)
                  {
                      pp.first=moves[j];
                  }
                  else
                  {
                      pp.first=j;
                  }
                  q.push(pp);
          }
      }
      return step;
    }
   
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends