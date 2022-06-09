class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
       map<int,int>m;
    vector<int>v;
            int n=arr.size();
    for(int i=0;i<n;i++)
    {
        if(m[arr[i]]==0)v.push_back(arr[i]);
        m[arr[i]]=1;
    }
    int ans=0;
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        m[v[i]]+=m[v[i]-1];
        if(m[v[i]]>ans)ans=m[v[i]];
    }
    return ans;
    }
};