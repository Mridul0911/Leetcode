class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        set<vector<int>> st;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                int left=j+1;
                int right=nums.size()-1;
                while(left<right)
                {
                   long long sum=(long long)nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum<target)
                    {
                        left++;
                    }
                    else if(sum>target)
                    {
                        right--;
                    }
                    else
                    {
                        st.insert({nums[i],nums[j],nums[left],nums[right]});
                        right--;
                        left++;
                    }
                }
            }
        }
        for(auto it:st)
        {
            ans.push_back(it);
        }
        return ans;
        
    }
};