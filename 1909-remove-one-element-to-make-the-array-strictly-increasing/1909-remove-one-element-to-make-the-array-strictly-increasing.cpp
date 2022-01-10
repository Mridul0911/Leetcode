class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) 
    {
         bool flag = true;
         for(int i = 0; i<nums.size(); i++){
             vector<int>ans;
             flag = true;
             for(int j = 0; j<nums.size(); j++){
                 if(i == j){
                     continue;
                 }
                
                 ans.push_back(nums[j]);
			}
                    
             for(int j = 1; j<ans.size(); j++){
                 if(ans[j-1]>=ans[j]){ 
                     flag = false;
                     break;
                 }
             }
            
             if(flag)return flag;
         }
        
            return false;
    }
};