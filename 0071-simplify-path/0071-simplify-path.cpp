class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int i=0;
        int n=path.length();
        for(int i=0;i<n;i++)
        {
            if(path[i]=='/')
            {
                continue;
            }
            string s="";
            while(i<n && path[i]!='/')
            {
                s+=path[i];
                i++;
            }
            if(s==".")
            {
                continue;
            }
            else if(s=="..")
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }
            else
            {
                st.push(s);
            }
        }
        string ans="";
        while(!st.empty())
        {
            ans="/"+st.top()+ans;
            // cout<<st.top()<<endl;
            st.pop();
        }
        if(ans.size()==0)
        {
            return "/";
        }
        return ans;
    }
};