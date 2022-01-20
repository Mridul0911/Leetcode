class Solution {
public:
         void sub(int index,vector<int> &nums,vector<int> &arr,set<vector<int>> &ans,int n)
        {
                if(index==n)
                {
                        ans.insert(arr);
                        return;
                }
                arr.push_back(nums[index]);
                sub(index+1,nums,arr,ans,n);
                arr.pop_back();
                sub(index+1,nums,arr,ans,n);
        }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         sort(nums.begin(),nums.end());
            int n=nums.size();
           set<vector<int>> ans;
            vector<int> inp;
            sub(0,nums,inp,ans,n); 
            vector<vector<int>> ans2;
            for(auto it:ans)
            {
                    ans2.push_back(it);
            }
            return ans2;
   }
};