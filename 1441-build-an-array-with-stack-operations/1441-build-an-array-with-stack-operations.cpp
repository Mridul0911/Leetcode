class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
            int num=1;
            int ind=0;
            for(int i=0;i<target.size();i++)
            {
                   while(target[i]!=num)
                   {
                           ans.push_back("Push");
                           ans.push_back("Pop");
                           num++;
                   }
                   ans.push_back("Push");
                   num++;
            }
            return ans;
    }
};