class Solution {
public:
        int isValid(string &s)
        {
                if(s.length()>3)
                {
                        return false;
                }
                if(s.length()>1 && s[0]=='0')
                {
                        return false;
                }
                int h=stoi(s);
                if(h<0 || h>255)
                {
                        return false;
                }
                return true;
        }
        void find(int index,string s,vector<string> &temp,vector<string> &ans)
        {
                if(index==s.size())
                {
                        if(temp.size()==4)
                        {
                                string gg="";
                                for(int k=0;k<temp.size();k++)
                                {
                                        gg+=temp[k];
                                        gg+='.';
                                }
                                gg.pop_back();
                                ans.push_back(gg);
                                return;
                        }
                }
                string g="";
                for(int i=index;i<s.size();i++)
                {
                        g+=s[i];
                        if(isValid(g))
                        {
                            temp.push_back(g);
                            find(i+1,s,temp,ans);
                            temp.pop_back();
                        }
                }
        }
    vector<string> restoreIpAddresses(string s) {
        vector<string> temp;
            vector<string> ans;
            find(0,s,temp,ans);
            return ans;
    }
};