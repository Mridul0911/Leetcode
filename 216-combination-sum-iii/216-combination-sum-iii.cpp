class Solution {
public:
        void subsq(int index,vector<vector<int>> &ans,vector<int> &ds,vector<int> &nums,int k,int target)
        {
                if(target==0)
                {
                        if(ds.size()==k)
                        {
                                ans.push_back(ds);
                        }
                }
                for(int i=index;i<nums.size();i++)
                {
                        if(i>index && nums[i]==nums[i-1]) continue;
                        if(nums[i]>target)
                        {
                                break;
                        }
                        ds.push_back(nums[i]);
                        subsq(i+1,ans,ds,nums,k,target-nums[i]);
                        ds.pop_back();
                }
                
        }
    vector<vector<int>> combinationSum3(int k, int n) {
        
            vector<int> nums;
            for(int i=1;i<=9;i++)
            {
                    nums.push_back(i);
            }
            vector<vector<int>> ans;
            vector<int> inp;
            subsq(0,ans,inp,nums,k,n);
            return ans;
            
            
            
    }
};