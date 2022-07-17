class Solution {
public:
        int getSum(int num)
        {
             int sum=0;
                while(num!=0)
                {
                        sum+=num%10;
                        num=num/10;
                        
                        
                }
                return sum;
        }
    int maximumSum(vector<int>& nums) {
     unordered_map<int,vector<int>> mp;
        for (auto num: nums) {
            int s= getSum(num); 
            mp[s].push_back(num); 
        }    
            int ans=-1;
            for(auto it:mp)
            {
                    if(it.second.size()>1)
                    {
                            auto values= it.second; 
                            sort(values.rbegin(), values.rend());
                            ans= max(ans, values[0]+ values[1]); 
                    }
            }
            
            return ans;
    }
};