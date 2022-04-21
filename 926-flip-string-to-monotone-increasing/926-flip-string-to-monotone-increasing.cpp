class Solution {
public:
    int minFlipsMonoIncr(string s) {
       int t=s.find('1');
            int count=0;
       
       int one=0;
            for(auto it:s)
            {
                    if(it=='1')
                    {
                            one++;
                    }
            }
            int flip=one;
       for(int i=s.length()-1;i>=0;i--)
       {
               if(s[i]=='0')
               {
                       count++;
               }
               else
               {
                       one--;
               }
               flip=min(count+one,flip);
       }
            return flip;
            
    }
};