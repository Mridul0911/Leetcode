class Solution {
public:
    int takeCharacters(string s, int k) {
       unordered_map<char,int> mp;
            for(auto it:s)
            {
                    mp[it]++;
            }
           if(mp['a']<k || mp['b']<k || mp['c']<k) 
           {
                   return -1;
           }
           int window=0;
            int j=0;
            int ans=INT_MAX;
            int n=s.size();
           for(int i=0;i<s.size();i++) 
           {
                   mp[s[i]]--;
                   window++;
                   while(mp[s[i]]<k)
                   {
                       mp[s[j]]++; 
                           cout<<s[j]<<" ";
                           j++;
                       window--;
                   }
                   cout<<endl;
                   ans=min(ans,n-window);  
           }
           return ans;
    }
};