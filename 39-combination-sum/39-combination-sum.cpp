class Solution {
public:
        void subsequence(int index,int target,vector<int> &candidates,vector<vector<int>> &ans,vector<int> &inp)
        {
                if(index==candidates.size())
                {
                        if(target==0)
                        {
                                ans.push_back(inp);
                        }
                        return;
                }
                if(candidates[index]<=target)
                {
                        inp.push_back(candidates[index]);
                        subsequence(index,target-candidates[index],candidates,ans,inp);
                        inp.pop_back();
                }
                        subsequence(index+1,target,candidates,ans,inp);
        }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
            vector<int> inp;
            subsequence(0,target,candidates,ans,inp);
            return ans;
            
            
    }
};