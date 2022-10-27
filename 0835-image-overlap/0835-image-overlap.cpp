class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
       vector<pair<int,int>> ind1;
       vector<pair<int,int>> ind2;
            
            for(int i=0;i<img1.size();i++)
            {
                    for(int j=0;j<img1.size();j++)
                    {
                            if(img1[i][j]==1)
                            {
                                    ind1.push_back({i,j});
                            }
                    }
            }
            for(int i=0;i<img2.size();i++)
            {
                    for(int j=0;j<img2.size();j++)
                    {
                            if(img2[i][j]==1)
                            {
                                    ind2.push_back({i,j});
                            }
                    }
            }
            map<pair<int,int>,int> mp;
                  int ans=0;
            int i=0;
            for(auto it:ind1)
            {
                    //cout<<i<<" "<<endl;
                    for(auto gg:ind2)
                    {
                           // cout<<it.first<<" "<<it.second<<endl;
                            //cout<<gg.first<<" "<<gg.second<<endl;
                           mp[{(gg.first-it.first),(gg.second-it.second)}]++;
                            ans=max(ans,mp[{(gg.first-it.first),(gg.second-it.second)}]);
                    }
                    //cout<<endl;
                    i++;
            }
          return ans;  
    }
};