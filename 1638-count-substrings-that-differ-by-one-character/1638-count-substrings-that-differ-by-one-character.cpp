class Solution {
public:
    int countSubstrings(string s, string t) {
      int n=s.length();
            int m=t.length();
            int ans=0;
            for(int i=0;i<n;i++)
            {
                    for(int j=0;j<m;j++)
                    {
                            int diff=0;
                          for(int k=0;i+k<n && j+k<m;k++)
                          {
                                  cout<<s[i+k]<<" "<<t[j+k]<<endl;
                                  if(s[i+k]!=t[j+k])
                                  {
                                       diff++;   
                                  }
                                  if(diff>1)
                                  {
                                          break;
                                  }
                                  ans+=diff;
                          }
                    }
            }
            return ans;
    }
};