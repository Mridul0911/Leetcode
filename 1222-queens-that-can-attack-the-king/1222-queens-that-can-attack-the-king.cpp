class Solution {
public:
        vector<pair<int,int>>pos = {{-1,-1}, {-1, 0}, {-1, 1}, {0, 1}, {1,1}, {1,0}, {1,-1}, {0,-1}};
        int n;
        int m;
        bool isvalid(int x, int y){
                if(x < 0 || x >= n || y < 0 || y >= m)return false;
                return true;
        }
        void solve(set<vector<int>> &ans,map<pair<int,int>,int> &mp,int xx,int yy,int x,int y)
        {
                if(mp.find({xx,yy})!=mp.end())
                {
                        ans.insert({xx,yy});
                        return;
                }
                int xxx=xx+x;
                int yyy=yy+y;
                if(isvalid(xxx,yyy))
                {
                        solve(ans,mp,xxx,yyy,x,y);
                }
        }
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        map<pair<int,int>,int> mp;
            n=8;
            m=8;
            for(auto it:queens)
            {
                    mp[{it[0],it[1]}]++;
            }
                set<vector<int>> ans;
            for(int i=0;i<8;i++)
            {
                   int x=pos[i].first;
                    int y=pos[i].second;
                     solve(ans,mp,king[0],king[1],x,y);    
            }
            vector<vector<int>> ams;
            for(auto it:ans)
            {
                    ams.push_back(it);
            }
            return ams;
    }
};