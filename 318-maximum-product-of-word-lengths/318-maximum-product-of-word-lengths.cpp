class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> v;
        for(string s:words)
        {
            int mask=0;
            for(char c:s)
            {
                mask|=(1<<(c-'a'));
            }
            v.push_back(mask);
        }
        int ans=0;
        for(int i=0;i<words.size()-1;i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                  if((v[i]&v[j])==0)
                  {
                      ans=max(ans,(int)words[i].size()*(int)words[j].size());
                      
                  }
            }
        }
        return ans;
      }
};