class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int maxi=max(x,y);
        if(maxi==x)
        {
            int ans=0;
            stack<int> st;
            st.push(s[0]);
            for(int i=1;i<s.size();i++)
            {
                if(!st.empty() && s[i]=='b' && st.top()=='a')
                {
                    ans++;
                    st.pop();
                }
                else
                {
                    st.push(s[i]);
                 }
            }
            string ans1="";
            while(!st.empty())
            {
                ans1+=st.top();
                st.pop();
            }
            int an=0;
            stack<int> str;
            for(int i=0;i<ans1.size();i++)
            {
                if(!str.empty() && ans1[i]=='b' && str.top()=='a')
                {
                    an++;
                    str.pop();
                }
                else
                {
                    str.push(ans1[i]);
                 }
            }
            int gg=ans*x+an*y;
            return gg;
        }
        else
        {
            int ans=0;
            stack<int> st;
            st.push(s[0]);
            for(int i=1;i<s.size();i++)
            {
                if(!st.empty() && s[i]=='a' && st.top()=='b')
                {
                    ans++;
                    st.pop();
                }
                else
                {
                    st.push(s[i]);
                 }
            }
            string ans1="";
            while(!st.empty())
            {
                ans1+=st.top();
                st.pop();
            }
            int an=0;
            stack<int> str;
            for(int i=0;i<ans1.size();i++)
            {
                if(!str.empty() && ans1[i]=='a' && str.top()=='b')
                {
                    an++;
                    str.pop();
                }
                else
                {
                    str.push(ans1[i]);
                 }
            }
            int gg=ans*y+an*x;
            return gg;
        }
    }
};