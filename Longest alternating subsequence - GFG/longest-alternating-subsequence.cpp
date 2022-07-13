// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int AlternatingaMaxLength(vector<int>&nums){
		    int ans=0;
		    int prevdiff=0;
		    int diff=0;
		    for(int i=0;i<nums.size()-1;i++)
		    {
		        diff=nums[i+1]-nums[i];
		        if(diff>0 && prevdiff<=0 || diff<0 && prevdiff>=0)
		        {
		            ans++;
		            prevdiff=diff;
		        }
		    }
		    return ans+1;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.AlternatingaMaxLength(nums);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends