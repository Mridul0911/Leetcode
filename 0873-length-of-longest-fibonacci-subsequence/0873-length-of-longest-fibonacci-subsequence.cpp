class Solution {
public:
        int find(int i,int j,vector<int> &arr,map<int,int> &mp)
        {
              if(mp.find(arr[i]+arr[j])==mp.end()) return 0;
              return 1+find(j,mp[arr[i]+arr[j]],arr,mp); 
        }
    int lenLongestFibSubseq(vector<int>& arr) {
        map<int,int> mp;
            for(int i=0;i<arr.size();i++)
            {
                mp[arr[i]]=i;    
            }
            int maxi=0;
            for(int i=0;i<arr.size()-2;i++)
            {
                    for(int j=i+1;j<arr.size()-1;j++)
                    {
                            if(mp.find(arr[i]+arr[j])==mp.end())
                            {
                                    continue;
                            }
                            else
                            {
                                    maxi=max(maxi,find(i,j,arr,mp));
                            }
                    }
            }
            if(maxi>0)
            {
                return maxi+2;        
            }
            else
            {
                return 0;
            }
     }
};