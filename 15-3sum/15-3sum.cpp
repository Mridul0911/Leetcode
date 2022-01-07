class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      int n=nums.size();
          sort(nums.begin(),nums.end());
            
            
            vector<vector<int>> ans;
            if(n<3)
            {
                    return ans;
            }
            
            for(int i=0;i<n;i++)
            {
                    if(i>0 && nums[i]==nums[i-1])
                      continue; 

                    int left=i+1;
                    int right=nums.size()-1;
                    while(left<right)
                    {
                            if(nums[left]+nums[right]+nums[i]==0)
                            {
                                    cout<<"hello"<<endl;
                                    ans.push_back(vector<int>{nums[i],nums[left],nums[right]});
                                    while(left<right && nums[left]==nums[left+1])
                                    {
                                           left++;                                            
                                    }
                                    while(left<right && nums[right]==nums[right-1])
                                    {
                                            right--;
                                    }
                                    left++;
                                 right--;
                              }
                            else if(nums[left]+nums[right]+nums[i]<0)
                            {
                              left++;      
                            }
                            else
                            {
                                    right--;
                            }
                            
                    }
                            
            }
            
            
            return ans;
            
            
    }
};