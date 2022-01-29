class Solution {
public:
        void solve(string &digits,map<char,string> &mp,string &s,vector<string> &ans,int index)
        {
                if(index==digits.length())
                {
                        ans.push_back(s);
                        return;
                }
                char currNumber=digits[index];
                string str=mp[currNumber];
                for(int i=0;i<str.size();i++)
                {
                        s+=str[i];
                        solve(digits,mp,s,ans,index+1);
                        s.pop_back();
                }
        }
    vector<string> letterCombinations(string digits) {
        map<char,string> mp{
                {'2',"abc"},
                {'3',"def"},
                {'4',"ghi"},
                {'5',"jkl"},
                {'6',"mno"},
                {'7',"pqrs"},
                {'8',"tuv"},
                {'9',"wxyz"},
             };
            string s="";
            vector<string> ans;
            if(digits.length()==0)
            {
                    return ans;
            }
            solve(digits,mp,s,ans,0);
            return ans;
    }
};