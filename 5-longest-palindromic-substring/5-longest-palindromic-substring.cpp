class Solution {
public:
    string longestPalindrome(string s) {
        int ans=0;
            int max =-1;
            int f=0;
            for(int i=0;i<s.size();i++)
            {
                    for(int j=s.size()-1;j>=0;j--)
                    {
                            if(s[i]==s[j])
                               {
                                   int a=i;
                                    int b=j;
                                    int flag=0;
                                      while(a<=b)
                                      {
                                              if(s[a]==s[b])
                                              {
                                                      a++;
                                                      b--;
                                              }
                                              else
                                              {
                                                      flag=1;
                                                      break;
                                              }
                                                
                                      }
                                    if(flag==0 && (j-i+1)>max)
                                    {
                                             max=j-i+1;
                                            f=i;
                                    }
                               }
                    }
                    
            }
            return s.substr(f,max);
        
            
            
            
            
            
            
            
    }
};