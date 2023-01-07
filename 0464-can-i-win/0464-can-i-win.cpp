vector<int> dp;
int originalSum;
class Solution {
public:
    bool isWinning(int bitmask,int n) {
        int sum=originalSum;
        for(int i=0;i<n;i++) {
            if((bitmask&(1<<i))==0) {
                sum-=(i+1);
            }
        }
        if(sum<=0) return false;
        if(dp[bitmask]!=-1) return dp[bitmask];
        int count=0;
        int temp=bitmask;
        while(temp) {
            if(temp&1) {
                if(!isWinning(bitmask^(1<<(count)),n)) {
                    return dp[bitmask]=true;
                }
            }
            temp>>=1;
            count++;
        }
        return dp[bitmask]=false;
    }
   bool canIWin(int n, int sum) {
          ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
        originalSum=sum;
        int total=n*(n+1)/2;
        if(total<sum) return false;
        if(total==sum) {
            if(n%2==0) return false;
            return true;
        }
        dp = vector<int>(1<<(n+1),-1);
           cout<<(1<<(n))-1<<endl;
        // for(int j=0;j<(int)(1<<n);j++) dp[j]=-1;
        if(sum==0) return true;
        return isWinning((int)(1<<n)-1,n);
    }
};