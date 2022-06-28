class Solution {
public:
        int find(string &s,string &t,int i,int j,vector<vector<int>> &dp)
        {
                if(j==0)
                {
                        return 1;
                }
                if(i==0)
                {
                        return 0;
                }
                if(dp[i][j]!=-1)
                {
                        return dp[i][j];
                }
                if(s[i-1]==t[j-1])
                {
                        return dp[i][j]=find(s,t,i-1,j-1,dp)+find(s,t,i-1,j,dp);
                }
                else
                {
                        return dp[i][j]=find(s,t,i-1,j,dp);
                }
        }
    int numDistinct(string s, string t) {
        int n=s.size();
            int m=t.size();
              vector<double> prev(m+1,0);
    
    prev[0]=1;
    
    for(int i=1;i<n+1;i++){
        for(int j=m;j>=1;j--)
        {
            
            if(s[i-1]==t[j-1])
                prev[j] = (prev[j-1] + prev[j]);
            else
                prev[j] = prev[j];
        }
    }
            return (int)prev[m];
    }
};