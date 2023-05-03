class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
            map<int,int> mp1;
            map<int,int> mp2;
            for(auto it:nums1)
            {
                    mp1[it]++;
            }
            for(auto it:nums2)
            {
                    mp2[it]++;
            }
            unordered_set<int> s1;
            unordered_set<int> s2;
                    
            for(int i=0;i<nums1.size();i++)
            {
                    auto it=mp2.find(nums1[i]);
                    if(it==mp2.end())
                    {
                            s1.insert(nums1[i]);
                    }
            }
            for(int i=0;i<nums2.size();i++)
            {
                    auto it=mp1.find(nums2[i]);
                    if(it==mp1.end())
                    {
                            s2.insert(nums2[i]);
                    }
            }
            vector<int> ans1,ans2;
            for(auto it:s1)
            {
                    ans1.push_back(it);
            }
            ans.push_back(ans1);
            for(auto it:s2)
            {
                    ans2.push_back(it);
            }
            ans.push_back(ans2);
            
            
            return ans;
            
    }
};