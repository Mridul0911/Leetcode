class Solution {
public:
     bool checkPalidrome(string s)
     {
        int l=0;
        int r=s.size()-1;
        while(l<r){
            if(s[l++]!=s[r--])return false;
        }
        return true;
     }
     bool isPalindrome(string s) {
         string result="";
        for(int i=0;i<s.size();i++){
            if(s[i]>=97 && s[i]<=122 || s[i]>=65 && s[i]<=90 || s[i]>=48 && s[i]<=57){
                result+=tolower(s[i]);
            }
        }
          return checkPalidrome(result);
            
    }
};