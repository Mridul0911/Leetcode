class Solution {
public:
    int isPoss(int target,vector<int> &nums)
    {
        long carry=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]>target-carry)
            {
                carry=(nums[i]-target)+carry;
            }
            else
            {
                carry=0;
            }
        }
        if(carry)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    int minimizeArrayValue(vector<int>& nums) {
        int low=*min_element(nums.begin(),nums.end());
        int high=*max_element(nums.begin(),nums.end());
        int ans=0;
        while(low<=high)
        {
            int mid=(low+high)>>1;
            if(isPoss(mid,nums))
            {
                high=mid-1;
                ans=mid;
            }
            else
            {
                low=mid+1;
            }
        }
        cout<<low<<" "<<high<<endl;
        return low;
    }
};