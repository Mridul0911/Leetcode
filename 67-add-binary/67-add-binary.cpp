class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
            
            int c=0;
            int n=a.length()-1;
            int m=b.length()-1;
            
            while(n>=0 || m>=0 || c==1)
            {
            c += n >= 0 ? a[n --] - '0' : 0;
            c += m >= 0 ? b[m --] - '0' : 0;
                    ans+=char(c%2+'0');
                    c=c/2;
                    }
            reverse(ans.begin(),ans.end());
            return ans;
            
            
            
    }
};