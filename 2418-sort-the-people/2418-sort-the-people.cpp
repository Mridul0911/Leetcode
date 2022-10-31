class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> inp;
            for(int i=0;i<names.size();i++)
            {
                    inp.push_back({heights[i],names[i]});
            }
            sort(inp.rbegin(),inp.rend());
            vector<string> answer;
            for(auto it:inp)
            {
                    answer.push_back(it.second);
            }
            return answer;
    }
};