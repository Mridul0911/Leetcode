class Solution {
public:
        void find(int n,string ans,set<string> &st,vector<string> &permu,int index)
        {
                if(index>=n)
                {
                      if(st.find(ans)==st.end())  
                      {
                              permu.push_back(ans);
                      }
                        return;
                }
                find(n,ans+'0',st,permu,index+1);
                if(permu.size()!=0)
                {
                        return;
                }
                find(n,ans+'1',st,permu,index+1);
                if(permu.size()!=0)
                {
                        return;
                }
        }
    string findDifferentBinaryString(vector<string>& nums) {
            set<string> s(nums.begin(),nums.end());
            vector<string> permu;
            string ans="";
            int n=nums[0].size();
            find(n,ans,s,permu,0);
            return permu[0];
    }
};