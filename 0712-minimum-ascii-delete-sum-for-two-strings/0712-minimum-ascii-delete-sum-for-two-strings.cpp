class Solution {
public:
    int dp[1001][1001];
    int find(string &s1,string &s2,int i,int j){
        if(i==s1.size() || j==s2.size())
        {
            int sum=0;
            for(int x=i;x<s1.size();x++) sum+=int(s1[x]);
            for(int y=j;y<s2.size();y++) sum+=int(s2[y]);
            return sum;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s1[i]==s2[j])
        {
            return find(s1,s2,i+1,j+1);
        }
        int case1=s1[i]+find(s1,s2,i+1,j);
        int case2=s2[j]+find(s1,s2,i,j+1);
        return dp[i][j]=min(case1,case2);
    }
    int minimumDeleteSum(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        return find(s1,s2,0,0);
    }  
};
