class Solution {
public:
  int find(int x,vector<int> &parent)
  {
     if(parent[x]==x)
     {
             return x;
     }
     else
     {
             return find(parent[x],parent);
     }
  }
  string smallestEquivalentString(string s1, string s2, string baseStr) {
          ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        vector<int> parent(26,0);
            int n=s1.size();
            for(int i=0;i<26;i++)
            {
                    parent[i]=i;
            }
            for(int i=0;i<n;i++)
            {
                    int x=find(s1[i]-'a',parent);
                    int y=find(s2[i]-'a',parent);
                    if(x!=y)
                    {
                        parent[max(x,y)]=min(x,y);
                    }
            }
            for(int i=0;i<baseStr.length();i++)
            {
                    baseStr[i]=find(baseStr[i]-'a',parent)+'a';
            }
            return baseStr;
    }
};