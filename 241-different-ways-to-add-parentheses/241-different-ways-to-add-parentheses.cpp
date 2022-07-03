class Solution {
public:
        map<string,vector<int>> mp;
        bool isOperator(char gg)
        {
                if(gg=='*' || gg=='-' || gg=='+')
                {
                        return true;
                }
                else
                {
                        return false;
                }
        }
        bool isOnlyNumber(string expression)
        {
                for(int i=0;i<expression.size();i++)
                {
                        if(expression[i]=='+' || expression[i]=='-' || expression[i]=='*')
                        {
                                return false;
                        }
                        
                }
                return true;
        }
        int findAns(int it,int it1,char operators)
        {
                if(operators=='*') return it*it1;
                if(operators=='+') return it+it1;
                if(operators=='-') return it-it1;
                return 0;
        }
        
    vector<int> diffWaysToCompute(string expression) {
            ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
            if(mp.find(expression)!=mp.end())
            {
                    return mp[expression];
            }
        vector<int> ans;
            int isNumber=0;
            for(int i=0;i<expression.size();i++ )
            {
                    if(isOperator(expression[i]))
                    {
                        isNumber=1;
                      vector<int> leftPart=diffWaysToCompute(expression.substr(0,i));
                      vector<int> rightPart=diffWaysToCompute(expression.substr(i+1));
                      for(auto it:leftPart)       
                      {
                              for(auto it1:rightPart)
                              {
                                      int ans1=findAns(it,it1,expression[i]);
                                      ans.push_back(ans1);
                              }
                      }
                     }
            }
            if(!isNumber)
            {
                    ans.push_back(stoi(expression));
            }
            return mp[expression]=ans;
    }
};