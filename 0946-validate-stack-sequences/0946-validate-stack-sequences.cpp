class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int x=pushed[0];
        int j=0;
        int y=popped[j];
        stack<int> st;
        for(int i=0;i<pushed.size();i++)
        {
            st.push(pushed[i]);
            cout<<pushed[i]<<endl;
            while(!st.empty() && st.top()==y)
            {
                st.pop();
                j++;
                if(j==popped.size() && st.empty())
                {
                    return true;
                }
                y=popped[j];
            }
        }
        // cout<<j<<endl;
        if(j==popped.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};