class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
            st.push(0);
            for(auto i:s)
            {
                    if(i=='(')
                    {
                            st.push(0);
                    }
                    else
                    {
                            int ele=st.top();
                            st.pop();
                            int val=0;
                            if(ele>0)
                            {
                                    val=ele*2;
                            }
                            else  if(ele==0)
                            {
                                    val=1;
                            }
                            st.top()+=val;
                    }
            }
            return st.top();
    }
};