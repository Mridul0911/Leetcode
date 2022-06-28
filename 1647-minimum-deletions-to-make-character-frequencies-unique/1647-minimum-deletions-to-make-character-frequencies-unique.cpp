class Solution {
public:
    int minDeletions(string s) {
        map<char,int> mp;
            for(auto it:s)
            {
                    mp[it]++;
            }
            set<int> st;
            int ans=0;
            for(auto it:mp)
            {
                    int x=it.second;
                    while(st.find(x)!=st.end())
                    {
                          x--;
                         ans++;   
                    }
                    if(x>0)
                    {
                        st.insert(x);
                    }
            }
            return ans;
    }
};