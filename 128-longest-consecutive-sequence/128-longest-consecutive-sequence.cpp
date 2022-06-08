class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
         map<int,int> mp;
    for(int i=0;i<arr.size();i++)
    {
        mp[arr[i]]++;
    }
    int mx=0;
            int n=arr.size();
    for(int i=0;i<n;i++)
    {
        int prev=arr[i]-1;
        if(mp[prev]==0)
        {
            int j = arr[i];
            while (mp[j]!=0) 
            {
                j++;
            }
            mx = max(mx, j - arr[i]);
        }
    }    
    return mx;
    
            
            
    }
};