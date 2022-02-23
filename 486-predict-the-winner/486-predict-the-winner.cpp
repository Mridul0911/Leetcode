class Solution {
public:
        int find(vector<int> &nums,int i,int j)
        {
                if(i>j)
                {
                        return 0;
                }
                int left=nums[i]+min(find(nums,i+2,j),find(nums,i+1,j-1));
                int right=nums[j]+min(find(nums,i+1,j-1),find(nums,i,j-2));
                return max(left,right);
        }
    bool PredictTheWinner(vector<int>& nums) {
         int i=0;
            int j=nums.size()-1;
            int total=0;
            for(auto i:nums)
            {
                    total+=i;
            }
            int player1=find(nums,i,j);
           if(player1>=total-player1)
           {
                   return true;
           }
            else
            {
                    return false;
            }
            
    }
};