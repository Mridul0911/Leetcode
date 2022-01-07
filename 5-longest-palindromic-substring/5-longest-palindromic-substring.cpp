class Solution {
public:
        bool check(int i,int j,vector<vector<bool>> &palin)
        {
                if(i<0 || j<0 || i>=palin.size() || j>=palin.size())
                {
                        return true;
                }
                return palin[i][j];
       }
    string longestPalindrome(string s) {
     int n=s.length();
            int a=0;
            int b=0;
            int max=0;
            vector<vector<bool>> palin(n,vector<bool>(n,true));
            for(int i=n-1;i>=0;i--)
            {
                    for(int j=i;j<n;j++)
                    {
                            if(s[i]==s[j] && check(i+1,j-1,palin)){
                                    palin[i][j]=true;
                                    if(j-i+1>max)
                                    {
                                            max=j-i+1;
                                            a=i;
                                            b=j;
                                    }
                            }
                            else
                            {
                                    palin[i][j]=false;
                            }
                    }
            }
            string res="";
            for(int i=a;i<=b;i++)
            {
                    res+=s[i];
            }
            return res;
         }
};