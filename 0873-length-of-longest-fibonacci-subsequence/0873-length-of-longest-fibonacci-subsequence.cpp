class Solution {
public:
        
        int find(int i,int j,vector<int> &arr,map<int,int> &mp,vector<vector<int>> &dp)
        {
                
              if(mp.find(arr[i]+arr[j])==mp.end()) return 0;
                if(dp[i][j]!=-1)
                {
                        return dp[i][j];
                }
              return dp[i][j]=1+find(j,mp[arr[i]+arr[j]],arr,mp,dp); 
        }
    int lenLongestFibSubseq(vector<int>& arr) {
        map<int,int> mp;
            for(int i=0;i<arr.size();i++)
            {
                mp[arr[i]]=i;    
            }
            vector<vector<int>> dp(1001,vector<int>(1001,-1));
            int maxi=0;
            for(int i=0;i<arr.size()-2;i++)
            {
                    for(int j=i+1;j<arr.size()-1;j++)
                    {
                            if(mp.find(arr[i]+arr[j])==mp.end())
                            {
                                    continue;
                            }
                            else
                            {
                                    maxi=max(maxi,find(i,j,arr,mp,dp));
                            }
                    }
            }
            if(maxi>0)
            {
                return maxi+2;        
            }
            else
            {
                return 0;
            }
     }
};