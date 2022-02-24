class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
            auto prev=intervals[0];
            int ans=0;
            for(int i=1;i<intervals.size();i++)
            {
                    vector<int> rece=intervals[i];
                    cout<<prev[0]<<" "<<rece[0]<<" "<<prev[1]<<" "<<rece[1]<<endl;
                    if(prev[0]<rece[0] && prev[1]>=rece[1])
                    {
                            ans++;
                    }
                    else if(prev[0]==rece[0] && prev[1]<=rece[1])
                    {
                            cout<<"HELLO";
                            ans++;
                            prev=rece;
                    }
                    else
                    {
                            prev=rece;
                            
                    }
            }
            return intervals.size()-ans;
            
    }
};