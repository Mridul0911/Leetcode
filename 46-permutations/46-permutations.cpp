class Solution {
public:
        void permut(int index,vector<int> nums,vector<int> &ds,vector<vector<int>> &ans)
        {
                if(index==nums.size())
                {
                        ans.push_back(nums);
                }
                for(int i=index;i<nums.size();i++)
                {
                       // if (i!=index && nums[i]==nums[index]) continue;
                        swap(nums[index],nums[i]);
                        permut(index+1,nums,ds,ans);
                       // swap(nums[index],nums[i]);
                        
                }
        }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
            vector<int> ds;
            permut(0,nums,ds,ans);
                  return ans;
            
            
    }
};