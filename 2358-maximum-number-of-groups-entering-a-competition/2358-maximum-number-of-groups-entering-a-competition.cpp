class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        sort(grades.begin(),grades.end());
        int n=grades.size();
        int group=1;
        int ans=0;
        while(group<=n)
        {
            ans++;
            n=n-group;
            group++;
        }
        return ans;
    }
    // 3 5 6 7 12
};
