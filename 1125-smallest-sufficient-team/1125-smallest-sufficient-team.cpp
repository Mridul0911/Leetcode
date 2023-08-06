class Solution {
public:
    int minPeople(int n,int skills,vector<vector<string>>& a,vector<vector<int>>& dp,map<string,int> &mp) {
        if(skills==0) return dp[n][skills]=0;
        if(n==0) return dp[n][skills]=INT_MAX;
        if(dp[n][skills]!=-1) return dp[n][skills];
        int k=skills;
        int mn=minPeople(n-1,skills,a,dp,mp);
        for(int i=0;i<(int)a[n-1].size();i++) {
            if(mp.find(a[n-1][i])!=mp.end()) {
                int y=mp[a[n-1][i]];
                if(skills&(1<<y)) {
                    skills^=(1<<y);
                }
            }
        }
        int temp=minPeople(n-1,skills,a,dp,mp);
        if(temp!=INT_MAX) 
        mn=min(mn,1+temp);
        return dp[n][k]=mn;
    }
   
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int cnt=0;
        map<string,int> mp;
        for(int i=0;i<(int)req_skills.size();i++) {
            if(mp.find(req_skills[i])!=mp.end()) continue;
            mp[req_skills[i]]=cnt;
            cnt++;
        }
        int n=people.size();
        vector<vector<int> > dp(n+1,vector<int>(1<<cnt,-1));
        int x=minPeople(n,(1<<cnt)-1,people,dp,mp);
        vector<int> ans;
        // cout<<x<<endl;
        int N=n,Skills=(1<<cnt)-1;
        // for(auto i:mp) cout<<i.first<<" "<<i.second<<endl;

        while(N>0&&Skills>0) {
            // cout<<N<<" "<<Skills<<endl;
            int x=dp[N-1][Skills];
            int k=Skills;
            for(int i=0;i<(int)people[N-1].size();i++) {
            if(mp.find(people[N-1][i])!=mp.end()) {
                int y=mp[people[N-1][i]];
                // cout<<y<<" "<<endl;
                if(k&(1<<y)) {
                    k^=(1<<y);
                }
            }
            
           }
            int y=(dp[N-1][k]!=INT_MAX)?(1+dp[N-1][k]):INT_MAX;
            // cout<<y<<" - "<<x<<endl;
            if(y<=x) {
                ans.push_back(N-1);
                Skills=k;
            }
            N--;
        }
        // cout<<N<<" "<<Skills<<endl;
        return ans;
    }
};