// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
        double ans=0;
        int n1=array1.size();
         int n2=array2.size();
         for(int i=0;i<n2;i++)
         {
             array1.push_back(array2[i]);
         }
         sort(array1.begin(),array1.end());
         int start=0;
         int end=array1.size()-1;
         int mid=start+(end-start)/2;
         if(end%2==0)
         {
             ans=array1[mid];
         }
         else
         {
             ans=array1[mid]+array1[++mid];
             ans=ans/2;
         }
         return ans;
    
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends