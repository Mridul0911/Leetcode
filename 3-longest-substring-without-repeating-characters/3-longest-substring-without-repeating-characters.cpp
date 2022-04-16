class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         if(s.length()==1)
         {
                 return 1;
         }
            int len=0;
            map<char,int> mp;
            int ans=0;
            for(int i=0;i<s.length();i++)
            {
                    string temp="";
                    temp+=s[i];
                    mp[s[i]]=1;
                    cout<<i<<" "<<temp<<endl;
                    int j=0;
                    for(j=i+1;j<s.length();j++)
                    {
                            auto it=mp.find(s[j]);
                            if(it!=mp.end())
                            {
                                 ans=max(ans,j-i);        
                                    break;
                            }
                            else
                            {
                                    temp+=s[j];
                                    mp[s[j]]=1;
                            }
                    }
                     ans=max(ans,j-i);        
                    cout<<i<<" "<<temp<<endl;
                    temp="";
                    mp.clear();
            }
            return ans;
}
};