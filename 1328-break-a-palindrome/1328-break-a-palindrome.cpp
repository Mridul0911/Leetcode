class Solution {
public:
    string breakPalindrome(string palindrome) {
       bool find = true;
        for(int i=0;i<palindrome.size()/2;i++)
        {
                if(palindrome[i]!='a')
                {
                        palindrome[i]='a';
                        find = false;
                        break;
                }
        }
        if(find)
        {
                palindrome[palindrome.size()-1]='b';
        }
        if(palindrome.size()==1)
        {
                return "";
        }
        return palindrome;
    }
};