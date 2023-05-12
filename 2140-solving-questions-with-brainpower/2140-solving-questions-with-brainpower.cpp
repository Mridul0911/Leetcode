class Solution {
public:
    long long find(vector<vector<int>> &inp,int index,vector<long long> &dp)
    {
        if(index>=inp.size())
        {
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
       long long case1=INT_MIN;
        long long case2=INT_MIN;
        case1=(long long)inp[index][0]+find(inp,index+inp[index][1]+1,dp);
        case2=(long long)find(inp,index+1,dp);
        return dp[index]=max(case1,case2);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size()+1,-1);
        return find(questions,0,dp);
    }
};