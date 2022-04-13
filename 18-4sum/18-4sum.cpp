class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
            set<vector<int>> curr;
            sort(nums.begin(),nums.end());
       for(int i=0;i<nums.size();i++)
       {
               for(int j=i+1;j<nums.size();j++)
               {
                       int newtarget=target-nums[i]-nums[j];
                    int left=j+1;
                       int right=nums.size()-1;
                       while(left<right)
                       {
                               int sum=nums[left]+nums[right];
                               if(sum>newtarget)
                               {
                                       right--;
                               }
                               else if(sum<newtarget)
                               {
                                       left++;
                               }
                               else
                               {
                                  curr.insert({nums[i],nums[j],nums[left],nums[right]});
                                       right--;
                                       left++;
                               }
                       }
                } 
         }       
            for(auto it:curr)
            {
                    ans.push_back(it);
            }
            return ans;
    }
};