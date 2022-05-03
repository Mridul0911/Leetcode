class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) 
    {
      vector<int> ans=nums;
            sort(ans.begin(),ans.end());
            //int end=nums.size()-1;
            int start=1e9;
            int end=-1e9;
            for(int i=0;i<nums.size();i++)
            {
               if(ans[i]!=nums[i])
               {
                       start=min(start,i);
                       end=max(end,i);
               }
            }
            if(start==1e9 || end==-1e9)
            {
                    return 0;
            }
            return end-start+1;
            
    }
};