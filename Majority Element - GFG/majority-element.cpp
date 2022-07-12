// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int n)
    {
        
        // your code here
        int maj_index=0;
        int count=1;
        for(int i=1;i<n;i++)
        {
            if(a[maj_index]==a[i])
            {
                count++;
            }
            else
            {
                count--;
            }
            if(count==0)
            {
                maj_index=i;
                count=1;
            }
        }
        int ele=a[maj_index];
        count=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==ele)
            {
                count++;
            }
        }
        if(count>n/2)
        {
            return a[maj_index];
        }
        else
        {
            return -1;
        }
        
    }
};

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends