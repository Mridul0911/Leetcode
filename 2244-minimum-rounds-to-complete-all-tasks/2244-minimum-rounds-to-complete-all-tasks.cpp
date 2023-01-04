class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
    map<int,int> mp; 
        for(auto it:tasks)
            {
            mp[it]++;
            }
        int ans=0;
        for(auto it:mp)
            {
            if(it.second<=1)
                {
                return -1;
                }
            }
        for(auto it:mp){
            ans+=(it.second)/3;
            if(it.second%3)
                {
                ans+=1;
                }
           }
        return ans; 
        
    }
};