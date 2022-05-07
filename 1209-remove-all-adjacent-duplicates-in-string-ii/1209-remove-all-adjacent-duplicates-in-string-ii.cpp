class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<int> st;
            int n=s.length();
            st.push(0);
            vector<int> freq(n,1);
            for(int i=1;i<n;i++)
            {
                    if(!st.empty())
                    {
                            if(s[st.top()]==s[i])
                            {
                                    freq[i]=freq[st.top()]+1;
                            }
                    }
                    st.push(i);
                    if(freq[st.top()]==k)
                    {
                            for(int i=0;i<k;i++)
                            {
                                    st.pop();
                            }
                    }
            }
            string res;
            while(!st.empty())
            {
                    res+=s[st.top()];
                    st.pop();
            }
            reverse(res.begin(),res.end());
            return res;
    }
};