class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int> hash(102, 0);
        for(auto it:nums)
        { 
            hash[it[0]]++; 
            hash[it[1]+1]--; 
        }
        int ans=0;
        int sum=0;
        for(int i=1;i<=100;++i)
        {
            sum+=hash[i];
            if(sum){
                ans++;
            }
        }
        return ans;
    }
};