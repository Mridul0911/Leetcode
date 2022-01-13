class Solution {
public:
        void sub(int index,vector<int> &nums,vector<int> &arr,vector<vector<int>> &ans,int n)
        {
                if(index==n)
                {
                        ans.push_back(arr);
                        return;
                }
                arr.push_back(nums[index]);
                sub(index+1,nums,arr,ans,n);
                arr.pop_back();
                sub(index+1,nums,arr,ans,n);
                 
        }
        
   vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
           vector<vector<int>> ans;
            vector<int> inp;
            sub(0,nums,inp,ans,n); 
return ans;            
    }
};