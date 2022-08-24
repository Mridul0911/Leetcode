class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
            nums.resize(2*n);
            for(int i=n;i<2*n;i++)
            {
                nums[i]=nums[i-n];
            }
            stack<pair<int,int>> st;
            st.push({nums[0],0});
            vector<int> ans(2*n,-1);
            for(int i=1;i<2*n;i++)
            {
                    if(st.size()==0)
                    {
                            st.push({nums[i],i});
                    }
                    while(!st.empty() && nums[i]>st.top().first)
                    {
                            ans[st.top().second]=nums[i];
                            st.pop();
                    }
                    st.push({nums[i],i});
            }
            vector<int> ans1;
            for(int i=0;i<n;i++)
            {
                    ans1.push_back(ans[i]);
            }
            return ans1;
      }
};