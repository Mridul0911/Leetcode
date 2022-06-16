// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
  public:
  void inorder(vector<int> &A,int index,int n,vector<int> &ans)
  {
      if(index>=n)
      {
          return;
      }
      inorder(A,2*index+1,n,ans);
      ans.push_back(A[index]);
      inorder(A,2*index+2,n,ans);
  }
  void swap(vector<int> &arr,int i,int j)
  {
      int temp=arr[i];
      arr[i]=arr[j];
      arr[j]=temp;
  }
    int minSwaps(vector<int>&arr, int n){
        //Write your code here
        vector<int> ans;
        inorder(arr,0,n,ans);
        vector<int> temp=ans;
        sort(temp.begin(),temp.end());
        map<int,int> mp;
        for(int i=0;i<ans.size();i++)
        {
            mp[ans[i]]=i;
        }
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            if(ans[i]!=temp[i])
            {
                int gg=ans[i];
                count++;
                int index=mp[temp[i]];
                swap(ans,i,mp[temp[i]]);
                mp[gg]=mp[temp[i]];
                mp[temp[i]]=i;
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
	    cin >> n;
	    vector<int>A(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> A[i];
	    }
	    Solution ob;
	    int ans = ob.minSwaps(A, n);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends