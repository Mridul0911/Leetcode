class Solution {
public:
        void solve(vector<int> &nums,set<vector<int>> &ans,int index)
        {
                if(index==nums.size())
                {
                        ans.insert(nums);
                }
                for(int i=index;i<nums.size();i++)
                {
                        swap(nums[index],nums[i]);
                        solve(nums,ans,index+1);
                        swap(nums[index],nums[i]);
                }
        }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         set<vector<int>> ans;
            vector<vector<int>> ans1;
            solve(nums,ans,0);
            for(auto it:ans)
            {
                    ans1.push_back(it);
            }
            return ans1;
        }
};