//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findRange(string str, int n) {
        // code here
        vector<int> ans;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(str[i]-'0'==1)
            {
                count++;
            }
        }
        if(count==n)
        {
            return {-1};
        }
        int max=0;
        int sum=0;
        int p=0;
        int left=0;
        int right=0;
        int idx;
        for(int i=0;i<n;i++)
        {
            if(str[i]-'0'==0)
            {
                idx=1;
            }
            else
            {
                idx=-1;
            }
            sum=sum+idx;
            if(sum>max)
            {
                max=sum;
                left=p;
                right=i;
            }
            else if(sum<0)
            {
                p=i+1;
                sum=0;
            }
        }
        ans.push_back(left+1);
        ans.push_back(right+1);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        Solution ob;
        auto ans = ob.findRange(s, n);

        if (ans.size() == 1) {
            cout << ans[0] << "\n";
        } else {
            cout << ans[0] << " " << ans[1] << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends