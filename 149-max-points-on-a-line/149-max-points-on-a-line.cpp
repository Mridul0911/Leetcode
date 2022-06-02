class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
         sort(points.begin(),points.end());
        int count=0;
        if(points.size()==1)
        {
                return 1;
        }
        int ans=0;
      int n=points.size();
             int gg;
          
  for(int i=0;i<n;i++)
  {
        unordered_map<long double,int> mp; 
        count=0;
        for(int j=0;j<n;j++)
        {
                double m;
                if(i!=j){
            if(points[j][0] == points[i][0]){
                count++;
            }
                    else{
            int y = points[j][1]-points[i][1];
            int x = points[j][0]-points[i][0];
             m = (y * 1.0) / (x * 1.0);
            mp[m]++;
                    }
            gg = max(count, mp[m]);
              ans=max(ans,gg);
          }
        }
     }
       return max(count,ans+1);
    }
};