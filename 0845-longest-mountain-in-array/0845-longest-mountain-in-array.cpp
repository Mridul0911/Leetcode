class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans=0;
        int i=1;
        int n=arr.size();
        while(i<n)
        {
            int incr=0;
            int dcr=0;
            while(i<n && arr[i-1]<arr[i]) i++,incr++;
            while(i<n && arr[i-1]>arr[i]) i++,dcr++;
            if(incr>0 && dcr>0)
            {
                ans=max(ans,incr+dcr+1);
            }
            while(i<n && arr[i-1]==arr[i])
            {
                i++;
            }
        }
        return ans;
    }
};