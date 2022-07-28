class Solution {
public:
        vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
        {
                vector<vector<int>> ans;
                sort(intervals.begin(),intervals.end());
                vector<int> curr=intervals[0];
                for(auto it:intervals)
                {
                        if(curr[1]>=it[0])
                        {
                                curr[1]=max(curr[1],it[1]);
                        }
                        else
                        {
                                ans.push_back(curr);
                                curr=it;
                        }
                }
                ans.push_back(curr);
                return ans;
        }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.insert(intervals.begin(),newInterval);
        vector<vector<int>> ans=mergeIntervals(intervals);
         return ans;
    }
};