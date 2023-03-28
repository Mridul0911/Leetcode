class Solution {
public:  
         int find(vector<int> &days,vector<int> &costs,int ind,int val,vector<vector<int>> &dp)
         {
              if(ind>=days.size())  
              {
                    return 0;  
              }
              if(dp[ind][val]!=-1)
              {
                    return dp[ind][val];
              }
              if(days[ind]<=val) 
              {
                      return dp[ind][val]=find(days,costs,ind+1,val,dp);
              }
              else
              {
                      int case1=costs[0]+find(days,costs,ind+1,days[ind],dp);
               //       cout<<"case1"<<" :: "<<case1<<endl;
                      int case2=costs[1]+find(days,costs,ind+1,days[ind]+6,dp);
                 //     cout<<"case2"<<" :: "<<case2<<endl;
                      int case3=costs[2]+find(days,costs,ind+1,days[ind]+29,dp);
                  //    cout<<"case3"<<" :: "<<case3<<endl;
                      return dp[ind][val]=min(case1,min(case2,case3));
              }
        }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
            int n=days.size();
            vector<vector<int>> dp(365,vector<int>(500,-1));
         return find(days,costs,0,0,dp);
    }    
};
