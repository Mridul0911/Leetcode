class Solution {
public:
         void permut(int index,vector<int> &nums,vector<int> &ds,set<vector<int>> &ans)
        {
                if(index==nums.size())
                {
                        ans.insert(nums);
                }
                for(int i=index;i<nums.size();i++)
                {
                        swap(nums[index],nums[i]);
                        permut(index+1,nums,ds,ans);
                        swap(nums[index],nums[i]);
                }
        }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         set<vector<int>> ans;
            vector<int> ds;
            permut(0,nums,ds,ans);
            vector<vector<int>> ans1;
            for(auto i:ans)
            {
                    ans1.push_back(i);
            }
            return ans1;
            
            
            
            
            
    }
};