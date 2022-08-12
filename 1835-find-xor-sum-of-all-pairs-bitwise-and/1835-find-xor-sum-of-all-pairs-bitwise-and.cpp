class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int ans1=0;
        int ans2=0;
        for(auto x:arr1)ans1^=x;
        for(auto x:arr2)ans2^=x;
        return ans1&ans2;
    }
};