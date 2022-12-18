class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums){
       int n=nums.size();
            vector<int> ans(nums.size(),0);
            stack<pair<int,int>> st;
            for(int i=0;i<nums.size();i++)
            {
                    if(st.size()==0)
                    {
                            st.push({nums[i],i});
                    }
                    else
                    {
                            while(!st.empty() && nums[i]>st.top().first)
                            {
                                    ans[st.top().second]=i-st.top().second;
                                    st.pop();
                            }
                            st.push({nums[i],i});
                    }
            }
            return ans;
    }
};