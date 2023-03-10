class Solution {
public:
     int minSumOfLengths(vector<int>& a, int k) {
       int n=a.size();
        int i=0,sum=0;
        vector<int> dp(n,0),suff(n,INT_MAX);
        for(int j=0;j<n;j++) {
            sum+=a[j];
            while(sum>k) {
                sum-=a[i];
                i++;
            }
            if(sum==k) {
                dp[i]=j-i+1;
            }
        }
        if(dp[n-1]==0){
                suff[n-1]=INT_MAX;
        }
        else{
                suff[n-1]=dp[n-1];
        }
             
        for(int i=n-2;i>=0;i--) {
            if(dp[i]==0) suff[i]=suff[i+1];
            else suff[i]=min(suff[i+1],dp[i]);
        }
             // for(auto it:dp)
             // {
             //         cout<<it<<" ";
             // }
             // cout<<endl;
        int ans=INT_MAX;
        for(int i=0;i<n;i++) {
            if(dp[i]) {
                int j=i+dp[i];
                if(j<n && suff[j]!=INT_MAX) {
                    ans=min(ans,dp[i]+suff[j]);
                }
            }
        }
        if(ans==INT_MAX) return -1;
        else return ans;
     } 
};    