class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
       
        vector<int> n1(1001,0);
        int n=trips.size();
        for(int i=0;i<n;i++)
        {
           n1[trips[i][1]]+=trips[i][0];
           n1[trips[i][2]]-=trips[i][0];
        }
      int sum=0;
        for(int i=0;i<1001;i++)
        {
            sum+=n1[i];
            if(sum>capacity)
            {
                return false;
            }
            }
        return true;
    }
    
};