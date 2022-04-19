class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
     vector<int> temp1={1,4,7,2,5,8};
     vector<int> temp2={2,5,8,1,4,7};
            
         vector<int> mp(10,0);
            for(auto it:digits)
            {
                    mp[it]++;
            }
            int sum=0;
            for(int i=0;i<digits.size();i++)
            {
                    sum+=digits[i];
            }
            string s="";
            for(int i=0;i<digits.size();i++)
            {
                    s+=to_string(digits[i]);
            }
            
            
      while(sum%3!=0)
      {
              int x=sum%3;
              if(x==1)
              {
                      for(int i=0;i<temp1.size();i++)
                      {
                        auto it = find (digits.begin(), digits.end(), temp1[i]);
                        if (it != digits.end())
                        {
                             if (mp[temp1[i]]) {
                                --mp[temp1[i]];
                                sum -= temp1[i];
                                break;   
                        }
                        
                      }
              }
              }
              else
              {
                      for(int i=0;i<temp2.size();i++)
                      {
                       auto it = find (digits.begin(), digits.end(), temp2[i]);
                        if (it != digits.end())
                        {
                             if (mp[temp2[i]]) {
                                --mp[temp2[i]];
                                sum -= temp2[i];
                                break;   
                        }
                      }
                              
              }
      }
              }
       string ss="";
            for(int i=9;i>=0;i--)
            {
                    for(int j=0;j<mp[i];j++)
                    {
                            ss+=to_string(i);
                    }
            }
            cout<<ss[0]<<endl;
           if(ss[0]=='0')
           {
                   return "0";
           }
            else
            {
                   return ss;
            }
            

            
            
            
    }
};