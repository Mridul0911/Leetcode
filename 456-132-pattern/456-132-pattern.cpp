class Solution {
public:
    bool find132pattern(vector<int>& nums) {
     if(nums.size()<3)
     {
             return false;
     }
            vector<int> left_min(nums.size());
                   left_min[0] = nums[0];
     int n=nums.size();
            for(int i=1;i<n;i++)
            {
                    left_min[i]=min(nums[i],left_min[i-1]);
            }
           //        vector<int> right_min(nums.size());
            //right_min[n-1]=nums[n-1];
           // for(int i=n-2;i>=0;i--)
            //{
            //        right_min[i]=min(nums[i],right_min[i+1]);
            //}
           //for(int i=1;i<n-1;i++)
           //{
            //       if(nums[i]>left_min[i] && nums[i]>right_min[i] && right_min[i]>left_min[i])
              //     {
             //              return true;
              //     }
           //}
           // return false;
            set<int> ans;
            ans.insert(nums[n-1]);
            for(int i=n-2;i>=0;i--)
            {
                    int x=left_min[i];
                    if(nums[i]>x)
                    {
                            auto it=ans.upper_bound(x);
                            if(it!=ans.end())
                            {
                                   if(nums[i]>*it)
                                   {
                                            return true;
                                   }
                            }                    
                    }
                    ans.insert(nums[i]);
            }
            return false;
       }
};