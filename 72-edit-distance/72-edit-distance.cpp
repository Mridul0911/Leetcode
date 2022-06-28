class Solution {
public:
        int find(int i,int j,string &word1,string &word2,vector<vector<int>> &dp)
        {
             if(i==0)   
             {
                  return j;       
             }
             if(j==0)
             {
                       return i;
             }
                if(dp[i][j]!=-1)
                {
                        return dp[i][j];
                }
                if(word1[i-1]==word2[j-1])
                {
                        return dp[i][j]=find(i-1,j-1,word1,word2,dp);
                }
         return dp[i][j]=1+min(find(i,j-1,word1,word2,dp),min(find(i-1,j,word1,word2,dp),find(i-1,j-1,word1,word2,dp)));
        }
    int minDistance(string word1, string word2) {
        
            int n=word1.size();
            int m=word2.size();
            
            vector<int> prev(m+1,0);
            vector<int> curr(m+1,0);
            
            for(int j=0;j<=m;j++)
            {
                    prev[j]=j;
            }
            for(int i=1;i<=n;i++)
            {
                    curr[0]=i;
                    for(int j=1;j<=m;j++)
                    {
                         if(word1[i-1]==word2[j-1])
                         {
                             curr[j]=prev[j-1];
                         }
                         else
                         {
                             curr[j]=1+min(prev[j-1],min(prev[j],curr[j-1]));   
                         }
                    }
                    prev=curr;
            }
            return prev[m];
            
    }
};