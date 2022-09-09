class Solution {
public:
        static bool cmp(vector<int> &inp1,vector<int> &inp2)
        {
                if(inp1[0]==inp2[0])
                {
                        return inp1[1]>inp2[1];
                }
                else
                {
                        return inp1[0]<inp2[0];
                }
        }
    int numberOfWeakCharacters(vector<vector<int>>& inp) {
        sort(inp.begin(),inp.end(),cmp);
            int n=inp.size();
          int  maxi=inp[n-1][1];
            int count=0;
       for(int i=n-2;i>=0;i--)
        {	
            if(inp[i][1]<maxi)
            {
                count++;
            }
            maxi=max(maxi,inp[i][1]);
        }
        return count;
    }
};