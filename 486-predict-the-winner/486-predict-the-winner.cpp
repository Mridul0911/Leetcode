class Solution {
public:
      int find(vector<int>& nums,int i,int j)
    {
        if(i>j) return 0;
        int left = nums[i]+min(find(nums,i+2,j),find(nums,i+1,j-1));
        int right = nums[j]+min(find(nums,i,j-2),find(nums,i+1,j-1));
        return max(left,right);
    }
     bool PredictTheWinner(vector<int>& nums) 
     {
          int n=nums.size();
        int sum=0;
            for(auto i:nums)
            {
                    sum+=i;
            }
        int score=find(nums,0,n-1);
        if(score>=sum-score) return true;
        else return false;
     }
};