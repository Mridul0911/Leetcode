class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
          int maxi=0;
        int cnt;
        if(points.size()<=2) return points.size();
        for(int i=0;i<points.size();i++)
        {
            for(int j=i+1;j<points.size();j++)
            {
                 cnt=2;
                for(int k=0;k<points.size();k++)
                {
                    if(k!= i && k!=j)
                    {
                        if(((points[i][1]- points[j][1])*(points[i][0]-points[k][0]))==((points[i][0]- points[j][0])*(points[i][1]-points[k][1])))
                        {
                            cnt++;
                        }
                    }
                }
               maxi= max(maxi,cnt);
            }
      }
           return maxi;
    }
};