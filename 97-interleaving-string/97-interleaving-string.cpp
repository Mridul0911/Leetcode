class Solution {
public:
    bool find(int i,int j,int k,int l1,int l2,int l3,string s1,string s2,string s3,vector<vector<vector<int>>> &dp)
    {
            if(dp[i][j][k]!=-1)
            {
                    return dp[i][j][k];
            }
            if(i==l1 && j==l2 && k==l3)
            {
                    return true;
            }
           if(i>l1 || j>l2 || k>l3) 
           {
                   return false;
           }
            bool case1=false;
            bool case2=false;
            if(s1[i]==s3[k])
            {
                    case1=find(i+1,j,k+1,l1,l2,l3,s1,s2,s3,dp);
            }
            if(s2[j]==s3[k])
            {
                    case2=find(i,j+1,k+1,l1,l2,l3,s1,s2,s3,dp);
            }
            return dp[i][j][k]=case1||case2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int length1=s1.size();
            int length2=s2.size();
            int length3=s3.size();
            if((length1+length2)!=length3)
            {
                     cout<<"HELLO"<<endl;
                    return false;
            }
            vector<vector<vector<int>>> dp(105,vector<vector<int>>(105,vector<int>(205,-1)));
            return find(0,0,0,length1,length2,length3,s1,s2,s3,dp);
    }
};