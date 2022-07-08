class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
         int sum=0;
            int i=0;
            int j=0;
            int ans=INT_MAX;
            int n=nums.size();
            while(j<n)
            {
                sum+=nums[j];
                    if(sum<target)
                    {
                            j++;
                    }
                    else if(sum==target)
                    {
                            ans=min(ans,j-i+1);
                            j++;
                            sum-=nums[i];
                            i++;
                    }
                    else
                    {
                            ans=min(ans,j-i+1);
                            while(sum>target)
                            {
                                    sum-=nums[i];
                                    i++;
                                    if(sum>=target) ans=min(ans,j-i+1);
                            }
                            j++;
                    }
                    
            }
            if(ans==INT_MAX)
            {
                 return 0;           
            }
            else
            {
                    return ans;
            }
        
        
    }
};