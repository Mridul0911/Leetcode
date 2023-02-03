class Solution {
public:
    string convert(string s, int numRows) {
        int n = numRows ;
            if(n == 1)
            {
                return s ;
            }
     string ans[numRows];
        int y=0;
        bool flag=false;
        for(int i=0;i<s.length();i++)
        {
            ans[y]+=s[i];
            if(y==0)
            {
                flag=true;
            }
            if(y==numRows-1)
            {
                flag=false;
            }
            if(flag) y++;
            else y--;
        }
        string ans1="";
        for(int i=0;i<numRows;i++)
        {
            ans1+=ans[i];
            
        }
        return ans1;
    }
};