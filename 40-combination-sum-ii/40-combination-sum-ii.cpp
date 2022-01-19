class Solution {
public:
        void subsequence(int index,int target,vector<int> &nums,vector<vector<int>> &ans,vector<int> &inp)
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
                        subsequence(i+1,target-nums[i],nums,ans,inp);
                        inp.pop_back();
                }
           
        }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
             ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
       sort(candidates.begin(),candidates.end());
            vector<vector<int>> ans;
        vector<int> inp;
       subsequence(0,target,candidates,ans,inp);
      return ans;
    }
};