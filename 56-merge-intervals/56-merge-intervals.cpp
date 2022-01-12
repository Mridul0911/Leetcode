class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      
         vector<vector<int>> ans;
            sort(intervals.begin(),intervals.end());
          
            vector<int> th=intervals[0];
            
            for(auto it:intervals){
               if(th[1]>=it[0]){
                    th[1]=max(th[1],it[1]);   
               }
                    else{
                            ans.push_back(th);
                            th=it;
                    }
           }
                            ans.push_back(th);
            
                return ans;
            
            
            
}
};