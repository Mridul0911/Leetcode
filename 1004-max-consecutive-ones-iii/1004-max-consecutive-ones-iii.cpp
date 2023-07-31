class Solution {
public:
    int longestOnes(vector<int>& arr,int k) {
        int count=0;
        int i=0;
        int j=0;
        int n=arr.size();
        int ans=INT_MIN;
        while(j<n)
        {
            if(arr[j]==0)   
            {
                count++;
            }
            while(count>k)
            {
                if(arr[i]==0)
                {
                    count--;
                }
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};