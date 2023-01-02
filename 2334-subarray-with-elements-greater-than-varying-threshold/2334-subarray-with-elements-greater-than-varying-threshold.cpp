class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
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
           for(int i=0;i<nums.size();i++)
           {
                   int k=right[i]-left[i]-1;
                 //  cout<<right[i]<<" "<<left[i]<<endl;
                 //  cout<<k<<endl;
                   int z=(threshold)/(k);       
                   if(nums[i]>z) return k;    
           }
           return -1;
    }
};