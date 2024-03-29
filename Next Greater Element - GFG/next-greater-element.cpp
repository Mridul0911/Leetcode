//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template for C++ solution

class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        // Your code here
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[i]>arr[st.top()])
            {
                arr[st.top()]=arr[i];
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())
        {
            arr[st.top()]=-1;
            st.pop();
        }
        return arr;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution ob;
        
        vector <long long> res = ob.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends