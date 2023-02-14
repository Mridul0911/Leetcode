class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
            int c=0;
            int len1=a.length()-1;
            int len2=b.length()-1;
            while(len1>=0 || len2>=0 || c==1)
            {
                   c+=len1>=0?a[len1--]-'0':0;
                   c+=len2>=0?b[len2--]-'0':0;
                   ans+=char(c%2+'0');
                   c=c/2;
            }
            reverse(ans.begin(),ans.end());
            return ans;
   }
};