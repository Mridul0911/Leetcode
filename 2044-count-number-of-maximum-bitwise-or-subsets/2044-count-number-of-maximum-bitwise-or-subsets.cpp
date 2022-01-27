class Solution {
public:
     void solve(vector<int> &nums, int index, int max, int curr,int &ans)
	{
		if(index==nums.size())
		{
			if(curr==max)
				ans++;
			return;
		}
		solve(nums, index+1, max,curr,ans);
		solve(nums, index+1, max, curr|nums[index],ans);
	}
    int countMaxOrSubsets(vector<int>& nums) {
         int ans=0;
            int max_OR=0;
            int curr=0;
            for(int i=0;i<nums.size();i++)
            {
                    max_OR=(max_OR | nums[i]);
            }
            solve(nums,0,max_OR,0,ans);
            return ans;
            
   }
};