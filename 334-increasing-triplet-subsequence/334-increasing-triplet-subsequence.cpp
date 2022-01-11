class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
      int min1=INT_MAX;
            int min2=INT_MAX;
            for(int i=0;i<nums.size();i++)
            {
                    if(min1>=nums[i])
                    {
                            min1=nums[i];
                    }
                    else if(min2>=nums[i])
                    {
                            min2=nums[i];
                    }
                    else
                    {
                            cout<<min1<<" "<<min2<<" "<<nums[i];
                            return true;
                    }
            }
            return false;
            
            
            
           
            
            
    }
};