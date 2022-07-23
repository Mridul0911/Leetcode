class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
            int m=nums2.size();
            int ans=0;
            for(int i=0;i<nums1.size();i++)
            {
                    for(int j=0;j<nums2.size();j++)
                    {
                            if(ans>=n-i)return ans; 
                            if(nums1[i]==nums2[j])
                            {
                                    int x=i;
                                    int y=j;
                                    int count=0;
                                    while(x<n && y<m && nums1[x++]==nums2[y++])count++;
                                    ans=max(ans,count);
                            }
                    }
            }
            return ans;
    }
};