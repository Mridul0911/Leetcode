class Solution {
public:
       void solve(string digits,map<char,string> &mp,vector<string> &ans,string &s,int index)
       {
               if(index==digits.length())
               {
                       ans.push_back(s);
                       return;
               }
               char number=digits[index];
               string t=mp[number];
               for(int i=0;i<t.length();i++)
               {
                       s+=t[i];
                       solve(digits,mp,ans,s,index+1);
                       s.pop_back();
               }
       }
    vector<string> letterCombinations(string digits) 
    {
       map<char,string> mp={{'2',"abc"},
                            {'3',"def"},
                            {'4',"ghi"},
                            {'5',"jkl"},
                            {'6',"mno"},
                            {'7',"pqrs"},
                            {'8',"tuv"},
                            {'9',"wxyz"}
                        };
            vector<string> ans;
            if(digits.length()==0)
            {
                    return ans;
            }
            string s="";
            solve(digits,mp,ans,s,0);
    return ans;       
            
            
    }
};