class Solution {
public:
    #define M 1000000007
    #define ll long long
    int maxSumMinProduct(vector<int>& nums) {
        int n=nums.size();
        vector<ll> prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+ nums[i];
        }
         vector<int> left(nums.size());
            vector<int> right(nums.size());
            stack<int> st;
           for(int i=0;i<nums.size();i++) 
           {
               while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
               if(st.empty()) {
                       left[i]=-1;
               }
               else{
                   left[i]=st.top();
               }
               st.push(i);
           }
            st=stack<int>();
           for(int i=nums.size()-1;i>=0;i--) 
           {
               while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
               if(st.empty()) {
                       right[i]=nums.size();
               }
               else{
                   right[i]=st.top();
               }
               st.push(i);
           }
        ll ans=INT_MIN; 
        for(int i=0;i<n;i++)
        {
            int lefti=left[i]+1;
            int righti=right[i]-1;
            ll subArraySum=lefti==0?prefix[righti]:(prefix[righti]-prefix[lefti-1]);
            ans=max(ans,nums[i]*subArraySum);
        }
        return ans%M;
    }
};