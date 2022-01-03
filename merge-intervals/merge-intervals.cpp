class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      
         vector<vector<int>> mergeI;
            sort(intervals.begin(),intervals.end());
            vector<int> gg=intervals[0];
            
            for(auto it:intervals)
            {
                    if(it[0]<=gg[1])
                                 {
                                         gg[1]=max(gg[1],it[1]);
                                 }             
                                 else
                                 {
                                         mergeI.push_back(gg);
                                         gg=it;
                                 }
            }      
                                 mergeI.push_back(gg);
                                 return mergeI;
            
            
            
            
            
    }
};