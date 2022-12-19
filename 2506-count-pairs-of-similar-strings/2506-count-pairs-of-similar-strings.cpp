class Solution {
public:
    int similarPairs(vector<string>& words) {
        
            map<set<int>,int> mp;
            for(int i=0;i<words.size();i++)
            {
                    set<int> st;
                    for(auto it:words[i])
                    {
                            st.insert(it);
                    }
                    mp[st]++;
            }
            int ans=0;
            for(auto it:mp)
            {
                    if(it.second>1)
                    {
                            ans+=(it.second*(it.second-1))/2;
                    }
            }
            return ans;
    }
};