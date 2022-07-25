class Solution {
public:
    
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        map<double,long long> mp;
        long long finalans=0;
        for(auto it:rectangles)
        {
            double ans=1.0*it[1]/it[0];
            if(mp.find(ans)!=mp.end())
            {
                finalans+=mp[ans];
            }
            mp[ans]++;
        }
        return finalans;
    }
};