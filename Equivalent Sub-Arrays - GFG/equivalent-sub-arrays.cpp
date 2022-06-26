// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    int countDistinctSubarray(int arr[], int n)
    {
        set<int> st;
        for(int i=0;i<n;i++)
        {
            st.insert(arr[i]);
        }
        int sz=st.size();
        map<int,int> mp;
        int j=0;
        int count=0;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
            while(mp.size()>=sz && j<=i)
            {
                mp[arr[j]]--;
                count+=(n-i);
                if(mp[arr[j]]==0) mp.erase(arr[j]);
                 j++;
               
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends