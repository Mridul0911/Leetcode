class Solution {
public:
    bool isValidParenthesis(string& str){
    stack<char> s;
        int j=0;
        for(;j<str.size();j++){
            if(str[j]=='(') s.push(str[j]);
            else if(str[j]==')'){
                if(s.size()!=0) s.pop();
                else break;
            }
        }
        if(s.size()==0 && j==str.size()) return true;
        return false;
    }

    void helper(int opPa,int clPa,string& str,vector<string>& allStrings){
        if(opPa==0){
            for(int i=0;i<clPa;i++) str=str+')';
            allStrings.push_back(str);
            str=str.substr(0,str.size()-clPa);
            return;
        } 
        if(clPa==0){
            for(int i=0;i<opPa;i++) str=str+'(';
            allStrings.push_back(str);
            str=str.substr(0,str.size()-opPa);
            return;
        }
        
        str=str+'(';
        helper(opPa-1, clPa , str , allStrings);
        str=str.substr(0,str.size()-1);
        
        str=str+')';
        helper(opPa, clPa-1, str ,allStrings);
        str=str.substr(0,str.size()-1);
    }

    vector<string> generateParenthesis(int n) {
        int openingParenthesis=n;
        int closingParenthesis=n;
        vector<string> allStrings;
        string str="";
        helper(openingParenthesis,closingParenthesis,str,allStrings);
        vector<string> ans;
        for(int i=0;i<allStrings.size();i++){
            if(isValidParenthesis(allStrings[i])){
                ans.push_back(allStrings[i]);
            }
        }
        return ans;
    }
};