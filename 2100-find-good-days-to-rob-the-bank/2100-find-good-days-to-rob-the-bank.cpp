class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n=security.size();
        vector<int> pref(n,0);
        int cnt=1;
        pref[0]=1;
        for(int i=1;i<security.size();i++)
        {
            if(security[i]<=security[i-1])
            {
                cnt++;
            }
            else
            {
                cnt=1;
            }
            pref[i]=cnt;
        }
        vector<int> suff(n,0);
        suff[n-1]=1;
        cnt=1;
        for(int i=security.size()-2;i>=0;i--)
        {
            if(security[i]<=security[i+1])
            {
                cnt++;
            }
            else
            {
                cnt=1;
            }
            suff[i]=cnt;
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(pref[i]-1>=time && suff[i]-1>=time)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};