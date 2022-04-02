class Solution {
public:
        bool ispalindrome(string s)
        {
                string t=s;
                reverse(s.begin(),s.end());
                if(s==t)
                {
                        return 1;
                }
                else
                {
                        return 0;
                }
       
        }
        bool isPalin(string s,int left,int right)
        {
                while(left<right)
                {
                        if(s[left]!=s[right])
                        {
                                return false;
                        }
                        left++;
                        right--;
                }
                return true;
        }
        
        
        
        
    bool validPalindrome(string s) {
           
       if(ispalindrome(s))
       {
               return true;
       }
       int i=0;
            int j=s.length()-1;
            int count=0;
            while(i<=j)
            {
                if(s[i]!=s[j])
                {
                      //  cout<<s[i]<<" "<<s[j]<<endl;
                       return isPalin(s,i+1,j) || isPalin(s,i,j-1); 
                }
                   i++;
                    j--;
            }
            
                    return true;
            
    }
};