class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
            vector<bool> ans;
        for(int i=0;i<l.size();i++)
        {
                int left=l[i];
                int right=r[i];
                vector<int> temp;
                for(int i=left;i<=right;i++)
                {
                        temp.push_back(nums[i]);
                }
                sort(temp.begin(),temp.end());
                int flag=true;
                for(int i=1;i<temp.size()-1;i++)
                {
                        if(temp[i+1] - temp[i] != temp[1] - temp[0])
                        {
                                flag=false;        
                                break;
                        }
                }
                ans.push_back(flag);
        }
            return ans;
            
            
    }
};