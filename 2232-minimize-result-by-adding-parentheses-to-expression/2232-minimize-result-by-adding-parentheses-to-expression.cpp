class Solution {
public:
       
   int eval(string &s,int i,int j,int p)
   {
        int leftsum=1;
        if(i>0) 
        {
                leftsum=stoi(s.substr(0,i));
        }
        int b=stoi(s.substr(i,p-i));
        int c=stoi(s.substr(p+1,j-p));
        int rightsum=1;
        if(j+1<s.size()) 
        {
                rightsum=stoi(s.substr(j+1,s.size()-j));
        }
        return leftsum*(b+c)*rightsum;
    }
    
    string minimizeResult(string expression) {
        int middle=0;
            int start=0;
           int ans=INT_MAX;
            int end=expression.length();
            for(int i=0;i<expression.length();i++)
            {
                    if(expression[i]=='+')
                    {
                            middle=i;
                            break;
                    }
            }
           string ans1="";
           
            for(int i=0;i<middle;i++)
            {
                    for(int j=middle+1;j<expression.length();j++)
                    {
                            int num=eval(expression,i,j,middle);
                            if(num<ans)
                            {
                                    ans=num;
                                    ans1=expression;
                                    ans1.insert(i,"(");
                                    ans1.insert(j+2,")");
                            }
                    }
            }
            return ans1;
        }
};