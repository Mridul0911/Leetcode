class Solution {
public:
    string stringHash(string s, int k) {
        int t=0;
        string result="";
        while(t<s.size())
        {
            int sum=0;
            for(int i=t;i<t+k;i++)
            {
                sum=sum+(s[i]-'a');    
            }
            char c=sum%26+'a';
            result+=c;
            t+=k;
        }   
        return result;   
    }
};