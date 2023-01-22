class Solution {
public:
    int find(vector<int> &nums,int index,int k,vector<int> &dp)
     {
             if(index==nums.size())
             {
                     return 0;
             }
             if(dp[index]!=-1)
             {
                     return dp[index];
             }
             int ans=INT_MAX;
             unordered_map<int,int> mp;
             int length=0;
             mp.clear();
             for(int i=index;i<nums.size();i++)
             {
                    
                    if(mp[nums[i]])
                    {
                            if(mp[nums[i]]==1)
                            {
                                    length++;
                            }
                            length++;
                    }
                    mp[nums[i]]++;
                     int aage_wala=find(nums,i+1,k,dp);
                     ans=min(ans,length+k+aage_wala);
             }
             return dp[index]=ans;
     }
    int minCost(vector<int>& nums, int k) {
            int n=nums.size();
         vector<int> dp(nums.size()+1);
            dp[n]=0;
            for(int i=n-1;i>=0;i--)
            {
                     int ans=INT_MAX;
            unordered_map<int,int> mp;
             int length=0;
             mp.clear();
             for(int j=i;j<nums.size();j++)
             {
                    
                    if(mp[nums[j]])
                    {
                            if(mp[nums[j]]==1)
                            {
                                    length++;
                            }
                            length++;
                    }
                    mp[nums[j]]++;
                     int aage_wala=dp[j+1];
                     ans=min(ans,length+k+aage_wala);
             }
                dp[i]=ans;
            }
        
         return dp[0];
    }
};
