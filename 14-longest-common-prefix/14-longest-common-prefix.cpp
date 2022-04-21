class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
            string s=strs[0];
            for(int i=1;i<strs.size();i++)
            {
                    string ss=strs[i];
                    string ans="";
                    for(int j=0;j<s.length();j++)
                    {
                            if(s[j]==ss[j])
                             ans+=ss[j];
                            else
                            {
                                    break;
                            }
                    }
                    cout<<ans<<endl;
                    s=ans;
            }
            return s;
            
            
    }
};