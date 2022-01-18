class Solution {
public:
    vector<int> partitionLabels(string s) {
 
    vector<int> freq(26,-1);
            for(int i=0;i<s.size();i++)
            {
                    freq[s[i]-'a']=i;
            }
            // for(auto i:freq)
            // {
            //         cout<<i<<endl;
            // }
           vector<int> ans;
            int j=0;
            int curr=0;
            for(int i=0;i<s.size();i++)
            {
                    j=max(j,freq[s[i]-'a']);
                    if(i==j)
                    {
                            ans.push_back(i-curr);
                            curr=i+1;
                    }
            }
            for(int i=0;i<ans.size();i++)
            {
                    ans[i]=ans[i]+1;
            }
                return ans;    
    }
 };