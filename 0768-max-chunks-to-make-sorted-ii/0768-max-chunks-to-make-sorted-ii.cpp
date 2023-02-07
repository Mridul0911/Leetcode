class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
            vector<int> temp=arr;
            sort(temp.begin(),temp.end());
         map<int,vector<int>> mp;
            for(int i=0;i<temp.size();i++)
            {
                    mp[temp[i]].push_back(i);
            }
            int n=arr.size();
            int ans=0;
            int i=arr.size()-1;
            while(i>=0)
            {
                    if(temp[i]==arr[i])
                    {
                            ans++;
                            i--;
                    }
                    else
                    {
                          ans++;
                          int pos=mp[arr[i]].back();
                          mp[arr[i]].pop_back();
                          int prev=arr[i];
                          i--;
                          while(i>=0 && i>=pos)
                          {
                              if(arr[i]<=prev)        
                              {
                                      prev=arr[i];
                                      pos=mp[arr[i]].back();
                                      mp[arr[i]].pop_back();
                              }
                              i--;
                          }
                    }
            }
            return ans;
    }
};