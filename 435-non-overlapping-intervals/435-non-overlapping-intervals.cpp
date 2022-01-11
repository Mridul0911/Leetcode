class Solution {
        static bool cmp(vector<int> &a,vector<int> &b)
        {
                return a[1]<b[1];
        }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
       sort(intervals.begin(),intervals.end(),cmp);
//             for(auto i:intervals)
//             {
//                     for(auto gg:i)
//                     {
//                             cout<<gg<<" ";
//                     }
//                     cout<<endl;
//             }
//             return 0;
           auto i=intervals[0];
            int ans=0;
           for(auto gg:intervals)
           {
                   if(i[1]>gg[0])
                   {
                      ans++;     
                   }
                   else
                   {
                           i=gg;
                   }
           }
            return ans-1;
            
            
            
            
            
    }
};