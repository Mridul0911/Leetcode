class Solution {
public:
        void permut(int index,vector<int> &nums,vector<int> &ds,vector<vector<int>> &ans,int k)
        {
                if(ds.size()==k)
                {
                        ans.push_back(ds);
                }
                for(int i=index;i<nums.size();i++)
                {
                        ds.push_back(nums[i]);
                        permut(i+1,nums,ds,ans,k);
                        ds.pop_back();
                }
        }
    vector<vector<int>> combine(int n, int k) {
     vector<int> nums;
            vector<int> ds;
     
            for(int i=1;i<=n;i++)
            {
                    nums.push_back(i);
            }
            vector<vector<int>> ans;
            permut(0,nums,ds,ans,k);
                   return ans;
            
            
    }
};