//{ Driver Code Starts
//Initial Template for C++

#include <iostream>
using namespace std;


// } Driver Code Ends


#include<vector>
class Solution{
public:
    long long count(long long x) {
        long long cnt = 0, bits=0, temp = x;
        vector<long long> v, ones;
        while(x) {
            if((x&1) == 1) {
                cnt++;
                ones.push_back(cnt);
                v.push_back(bits);
            }
            bits++;
            x>>=1;
        }
        
        vector<vector<long long>> ncr(bits+1, vector<long long>(bits+1, 0));
        ncr[0][0] = 1;
        for(int i = 1; i <= bits; i++) {
            for(int j = 0; j <= i; j++) {
                if(j == 0 || j == i) ncr[i][j] = 1;
                else  {
                    ncr[i][j] += ncr[i - 1][j] + ncr[i - 1][j - 1];
                }
            }
        }
        
        long long ans = 0;
        for(int i = 0; i < ones.size(); i++) {
            ans += ncr[v[i]][ones[i]];   
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    
	int t;
	cin >> t;
	while (t-- > 0) {
	    long long x; cin >> x;
	    Solution ob;
	    cout << ob.count(x) << '\n';
	}
	return 0;
}
// } Driver Code Ends