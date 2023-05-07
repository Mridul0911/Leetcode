class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obs) {
        vector<int>temp,ans;
        temp.push_back(obs[0]);
        ans.push_back(1);
        for(int i=1;i<obs.size();i++)
        {
            auto itr=upper_bound(temp.begin(),temp.end(),obs[i]);
            if(itr==temp.end())
            {
                temp.push_back(obs[i]);
                ans.push_back(temp.size());
            }
            else
            {
                int idx=itr-temp.begin();
                temp[idx]=obs[i];
                ans.push_back(idx+1);
            }
        }
        return ans;
    }
};