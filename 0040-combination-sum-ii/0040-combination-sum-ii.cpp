class Solution {
public:
    void find(int index,int target,vector<int> &nums,vector<vector<int>> &ans,vector<int> &inp)
        {
          if(target==0)
          {
                  ans.push_back(inp);
                  return;
          }
                for(int i=index;i<nums.size();i++)
                {
                        if(i>index && nums[i]==nums[i-1])
                        {
                                continue;
                        }
                        if(nums[i]>target)
                        {
                                break;
                        }
                        inp.push_back(nums[i]);
                        find(i+1,target-nums[i],nums,ans,inp);
                        inp.pop_back();
                }
           
        }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> nums;
        sort(candidates.begin(),candidates.end());
        find(0,target,candidates,ans,nums);
        return ans;
    }
};