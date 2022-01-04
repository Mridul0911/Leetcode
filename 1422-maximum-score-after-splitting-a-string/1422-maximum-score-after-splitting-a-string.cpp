class Solution {
public:
    int maxScore(string s) {
      int finalans=0;
            for(int i=1;i<s.length();i++)
            {
                    string p=s.substr(0,i);
                    string pp=s.substr(i,s.length()-i);
                    int zero=0;
                    int one=0;
                    for(int j=0;j<p.length();j++)
                    {
                            if(p[j]=='0')
                            {
                                    zero++;
                            }
                    }
                    for(int k=0;k<pp.length();k++)
                    {
                            if(pp[k]=='1')
                            {
                                    one++;
                            }
                    }
                    int ans=one+zero;
                    finalans=max(finalans,ans);
            }
            return finalans;
            
    }
};