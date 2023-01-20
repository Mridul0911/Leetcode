class Solution {
public:
    int subarraysWithKDistinct(vector<int>& a, int k) {
        int n=a.size();
        set<int> s;
        map<int,deque<int> > mp;
        int st=0,j=0;
        int cnt=0;
        while(j<n) {
            mp[a[j]].push_back(j);
            while(mp.size()>k) {
                int end=j-1;
                int stIdx=*(--s.end());
                cnt+=end-stIdx+1;
                s.erase(mp[a[st]].front());
                mp[a[st]].pop_front();
                if(mp[a[st]].size()) {
                    s.insert(mp[a[st]].front());
                }
                else {
                    mp.erase(a[st]);
                }
                st++;
            }
           if(mp[a[j]].size()==1) {
                s.insert(j);
            }
            j++;
        }
        while(mp.size()==k) 
        {
            int end=n-1;
            int stIdx=*(--s.end());
            cnt+=end-stIdx+1;
            s.erase(mp[a[st]].front());
            mp[a[st]].pop_front();
            if(mp[a[st]].size()) {
                s.insert(mp[a[st]].front());
            }
            else break;
            st++;
        }
        return cnt;
    }
};