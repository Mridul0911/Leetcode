class Solution {
public:
    bool canChange(string start, string target) {
       
      vector<pair<char,int>> v;
        for(int i=0;i<start.length();i++)
        {
            if(start[i]=='L' || start[i]=='R')
            {
                v.push_back({start[i],i});
            }
        }
        int i=0;
        for(int j=0;j<target.length();j++)
        {
            if(target[j]=='L' || target[j]=='R')
            {
                if(i>=v.size() || v[i].first!=target[j])
                {
                    return false;
                }
                else
                {
                    if(v[i].first=='L' && v[i].second<j)
                    {
                        return false;
                    }
                    else if(v[i].first=='R' && v[i].second>j)
                    {
                        return false;
                    }
                    else
                    {
                        i++;
                    }
                }
            }
        }
        return i==v.size();
    }
};