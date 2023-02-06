class Solution {
public:
        vector<int> ans;
        vector<int> temp;
    Solution(vector<int>&nums) {
            temp=nums;
        ans=nums;
    }
    vector<int> reset() {
        return temp;
    }
    vector<int> shuffle() {
            int num=ans.size();
       for(int i=0;i<ans.size();i++)
       {
              int ind=rand()%num;
              swap(ans[i],ans[ind]);
       }
         return ans;
    }
};