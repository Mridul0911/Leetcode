class Solution {
public:
   
    int minSetSize(vector<int>& vec) 
    {
      unordered_map<int,int> mp;
            for(int i=0;i<vec.size();i++)
            {
                    mp[vec[i]]++;
            }
            priority_queue<pair<int,int>> pq;
            for(auto it:mp)
            {
                    pq.push({it.second,it.first});
            }
            int req=0;
            int ans=0;
            while(req<vec.size()/2)
            {
                    req+=pq.top().first;
                    pq.pop();
                    ans++;
            }
            return ans;
    }
};