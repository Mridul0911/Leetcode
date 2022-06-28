// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

int maxProfit(vector<int>&prices){
    //Write your code here..
    int n=prices.size();
            int cap=0;
            vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
            
            vector<vector<int>> ahead(2,vector<int>(3,0));
            vector<vector<int>> curr(2,vector<int>(3,0));
            
            
            
            for(int index=n-1;index>=0;index--)
            {
                    for(int buy=0;buy<=1;buy++)
                    {
                            for(int cap=1;cap>=0;cap--)
                            {
                                        if(buy)
                                        {
                                                curr[buy][cap]=max((-prices[index]+ahead[0][cap]),ahead[1][cap]);
                                        }
                                        else
                                        {
                                                curr[buy][cap]=max((prices[index]+ahead[1][cap+1]),ahead[0][cap]); 
                                        }
                            }
                            ahead=curr;
                    }
            }
            return curr[1][0];
}

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}
  // } Driver Code Ends