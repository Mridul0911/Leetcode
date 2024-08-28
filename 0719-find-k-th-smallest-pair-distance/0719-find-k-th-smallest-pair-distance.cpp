class Solution {
public:
    bool check(vector<int> &nums,int mid,int k)
    {   
        int n=nums.size();
        int j=1;
        int total=0;
        for(int i=0;i<n;i++)
        {
            while(j<n && nums[j]-nums[i]<=mid)
            {
                j++;
            }
            j--;
            total+=(j-i);
        }
        if(total>=k)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int low=0;
        int n=nums.size();
        int high=nums[n-1]-nums[0];
        while(low<high)
        {
            int mid=(low+high)/2;
            if(check(nums,mid,k))
            {
                high=mid;
            }
            else
            {
                low=mid+1;
            }                
        }
        return low;
    }
};