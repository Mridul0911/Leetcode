class Solution {
public:
    string addStrings(string num1, string num2) {
     int n=num1.length();
            int m=num2.length();
            int i=n-1;
            int j=m-1;
            
            int carry=0;
            string res="";
            while(i>=0 || j>=0 || carry)
            {
                  int sum=0;
                  if(i>=0)
                  {
                          sum+=num1[i]-'0';
                          i--;
                  }
                    if(j>=0)
                    {
                            sum+=num2[j]-'0';
                            j--;
                    }
                    sum+=carry;
                    carry=sum/10;
                    res=res+to_string(sum%10);
            }
            reverse(res.begin(),res.end());
            return res;
    
    
    
    }
};