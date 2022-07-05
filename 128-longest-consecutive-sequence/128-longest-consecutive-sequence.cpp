class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        if(arr.size()==0)return 0;
        map<int,int> mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]=i;
        } 
        vector<int>v;
        for(auto it:mp)
        {
            v.push_back(it.first);
  //          cout<<it.first<<endl;
        }
        int maxlen=1;
        int len=1;
        for(int i=1;i<v.size();i++)
        {
            if(v[i-1]+1==v[i])len++;
            else len=1;
            maxlen=max(len,maxlen);
        }
        return maxlen;
      }
};