class Solution {
public:
        /* void sub(int index,vector<int> &nums,vector<int> &arr,set<vector<int>> &ans,int n)
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
        } */
         void sub(int index,vector<int> &nums,vector<int> &arr,vector<vector<int>> &ans)
        {
                   ans.push_back(arr);
                 for(int i=index;i<nums.size();i++)
                 {
                    if(i!=index && nums[i]==nums[i-1]) continue;
                         arr.push_back(nums[i]);
                         sub(i+1,nums,arr,ans);
                         arr.pop_back();
                 }
              
         
         } 
        
        
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         sort(nums.begin(),nums.end());
            
           vector<vector<int>> ans;
            vector<int> inp;
            sub(0,nums,inp,ans); 
            
            return ans;
   }
};