class Solution {
public:
        
    string strWithout3a3b(int a, int b) {
        string res="";
        if(a==0)
        {
                for(int i=0;i<b;i++)
                {
                        res+="b";
                }
                return res;
        }
        if(b==0)
        {
                for(int i=0;i<a;i++)
                {
                        res+="a";
                }
                return res;
        }
        if(a>b)    
        {
                res+="aab";
                a-=2;
                b-=1;
        }
        else if(b>a)   
        {
                res+="bba";
                b-=2;
                a-=1;
                cout<<res<<a<<b<<endl;
        }
        else if(a==b)
        {
                res+="ab";
                a--;
                b--;
        }
        return res+strWithout3a3b(a,b);
    }
};