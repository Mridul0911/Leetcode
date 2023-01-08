//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long countKdivPairs(int arr[], int n, int k)
    {
        //code here
        unordered_map<int,int>mp;
        long long int cn =0;
        for( int i=0; i<n; i++){
             int temp=arr[i]%k;
            if(mp.find(k-temp)!=mp.end()){
                cn+=mp[k-temp];
            }
            if(mp.find(temp)!=mp.end() && temp==0){
                cn+=mp[temp];
            }
            mp[temp]++;
        }
        return cn;
        
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
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}

// } Driver Code Ends