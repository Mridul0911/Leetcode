class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int>v;
        v=nums;
        vector<int>v1;
        while(v.size()>1)
        {
            for(int i=0;i<v.size()-1;i++)
            {
                v1.push_back((v[i]+v[i+1])%10);
            }
            v.clear();
            v=v1;
            v1.clear();
            
        }
        return v[0];
    }
};