class Solution {
public:
    string makemaximum(int num,int max_sz)
    {
        string s=to_string(num);
        int n=s.size();
        for(int i=0;i<max_sz-n;i++)
        {
            s="0"+s;
        }
        return s;
    }
    unordered_set<string> findsame(int num,int max_sz)
    {
        string s=makemaximum(num,max_sz);
        unordered_set<string> st;
        st.insert(s);
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                swap(s[i],s[j]);
                st.insert(s);
                for(int i1=0;i1<n;i1++)
                {
                    for(int i2=i1+1;i2<n;i2++)
                    {
                        swap(s[i1],s[i2]);
                        st.insert(s);
                        swap(s[i1],s[i2]);
                    }
                }
                swap(s[i],s[j]);
            }
        }
        return st; 
    }
    int countPairs(vector<int>& nums) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        string s=to_string(maxi);
        int max_sz=s.size();
        int ans=0;
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++)
        {
            unordered_set<string> st=findsame(nums[i],max_sz);
            for(auto it:st)
            {
                if(mp.count(it))
                {
                    ans+=mp[it];
                }
            }
            string s=makemaximum(nums[i],max_sz);
            mp[s]++;
        }
        return ans;
    }
};