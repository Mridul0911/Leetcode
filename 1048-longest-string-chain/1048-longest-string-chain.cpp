class Solution {
public:
        bool isSubsequenceLength(string s,string p)
        {
                int i=0;
                for(;i<s.length();i++)
                {
                        if(s[i]!=p[i])
                        {
                                break;
                        }
                }
                for (int ai = i, bi = i + 1; ai<s.size();ai++,bi++) {
                    if (s[ai]!=p[bi]) 
                    {
                                return false;
                    }
                }
              //  cout<<s<<" "<<p<<endl;
                return true;
                
        }
        int dfs(int index,vector<string> &words,vector<int> &dp)
        {
                if(dp[index]!=-1)
                {
                        return dp[index];
                }
                int answer=1;
                for(int i=index+1;i<words.size();i++)
                {
                        if(words[i].length()-words[index].length()>1)
                        {
                                break;
                        }
                        if((words[i].length()==(words[index].length()+1)) && isSubsequenceLength(words[index],words[i]))
                        {
                                answer=max(1+dfs(i,words,dp),answer);
                        }
                }
                return dp[index]=answer;
        }
        static bool cmp(string &a,string &b)
        {
                return b.size()>a.size();
        }
    int longestStrChain(vector<string>& words) 
    {
            sort(words.begin(),words.end(),cmp);
            vector<int> dp(1001,-1);
        // for(auto it:words)
        // {
        // cout<<it<<" ";
        // }
        //     cout<<endl;
      int n=words.size();
         int maxi=1;
            for(int i=0;i<words.size();i++)
            {
                    maxi=max(maxi,dfs(i,words,dp));
            }
            return maxi;  
    }
};