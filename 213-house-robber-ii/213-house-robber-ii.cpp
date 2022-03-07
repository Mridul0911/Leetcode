class Solution {
public:
         int solve(vector<int>& arr){
    int n = arr.size();
     int prev = arr[0];
     int prev2 =0;
    
    for(int i=1; i<n; i++){
         int pick = arr[i];
        if(i>1)
            pick += prev2;
        int nonPick = 0 + prev;
        
        int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev= cur_i;
        
    }
    return prev;
}
    int rob(vector<int>& nums) {
        if(nums.size()==1)
        {
                return nums[0];
        }
            vector<int> inp1;
            vector<int> inp2;
            vector<int> dp(nums.size(),-1);
            for(int i=0;i<nums.size();i++)
            {
                    if(i!=0)
                    {
                         inp1.push_back(nums[i]);   
                    }
                    if(i!=nums.size()-1)
                    {
                            inp2.push_back(nums[i]);
                    }
            }
            int ans=solve(inp1);
            int ans1=solve(inp2);
            return max(ans,ans1);
            
    }
};