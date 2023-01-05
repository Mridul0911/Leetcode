class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
      sort(points.begin(), points.end(),
            [](auto &a, auto &b) -> bool {
                return a[1] < b[1]; 
            });
       int count=1;
        int burst=points[0][1];
        for(auto point:points)
        {
            if(point[0]>burst)
            {
                count++;
                burst=point[1];
            }
        }
        return count;
        
        
        
    }
    
};