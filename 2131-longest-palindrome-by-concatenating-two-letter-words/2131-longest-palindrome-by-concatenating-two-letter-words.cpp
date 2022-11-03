class Solution{
public:
    int longestPalindrome(vector<string>& words) 
    {
            map<string,int> m;
            for(auto it:words)
            {
                    m[it]++;
            }
            int ans=0;
            int flag=false;
            for(auto it:words)
            {
                  string s=it;
                  reverse(s.begin(),s.end());
                  if(s!=it && m[s]>0 && m[it]>0)        
                  {
                          m[s]--;
                          m[it]--;
                          ans+=4;
                  }
                  else if(s==it && m[s]>1)  
                  {
                          m[s]-=2;
                          ans+=4;
                  }
                  else if(s==it && !flag && m[s]>0)
                  {
                          m[s]--;
                          flag=true;
                          ans+=2;
                  }
            }
            return ans;
    }
};