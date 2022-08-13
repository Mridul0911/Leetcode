class Solution {
public:
        bool check(string s,int maxi,unordered_map<string,int> mp)
        {
                for(int i=0;i<s.size();i+=maxi)
                {
                        string gg=s.substr(i,maxi);
                     //   cout<<"INSIDE CHECK"<<" "<<s.substr(i,maxi)<<endl;
                        if(mp.find(gg)!=mp.end())
                        {
                                if((--mp[gg])==-1)
                                {
                                //        cout<<"HELLE"<<endl;
                                        return false;
                                }
                        }
                        else
                        {
                                return false;
                        }
                }
                return true;
        }
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> mp;
            for(auto it:words)
            {
                    mp[it]++;
            }
            int max_length=words.size()*words[0].size();
            int i=0;
            int len=words[0].size();
            vector<int> ans;
            while(i+max_length<=s.size())
            {
                    //cout<<s.substr(i,max_length)<<endl;
                    if(check(s.substr(i,max_length),len,mp))
                    {
                            ans.push_back(i);
                    }
                    i++;
            }
            return ans;
   }
};