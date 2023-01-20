class Solution {
public:
        set<vector<int>> st;
        void find(vector<int> &nums,int index,vector<int> &temp)
        {
                if(index==nums.size())
                {
                     if(temp.size()>=2)        
                     {
                            st.insert(temp);
                     }
                     return;
                }
                if(!temp.empty() && nums[index]>=temp.back())
                {
                        temp.push_back(nums[index]);
                        find(nums,index+1,temp);
                        temp.pop_back();
                }
                if(temp.empty())
                {
                        temp.push_back(nums[index]);
                        find(nums,index+1,temp);
                        temp.pop_back();
                }
                find(nums,index+1,temp);
        }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
       vector<vector<int>> ans;
        vector<int> gg;
            find(nums,0,gg);
            for(auto it:st)
            {
                    ans.push_back(it);
            }
            return ans;
    }
};