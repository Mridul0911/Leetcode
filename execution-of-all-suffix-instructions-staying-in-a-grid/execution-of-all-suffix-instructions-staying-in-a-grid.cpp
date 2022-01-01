class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        
            vector<int> res;
            int r=startPos[0];
            int c=startPos[1];
            for(int i=0;i<s.length();i++)
            {
                    int k=i;
                    int row=r;
                    int column=c;
                    int count=0;
                    while(k<s.length())
                    {
                           if(s[k]=='R')
                           {
                                   column++;
                                   if(column>=n)
                                   {
                                           break;
                                   }
                                   count++;
                           }
                           else if(s[k]=='L')
                           {
                                   column--;
                                   if(column<0)
                                   {
                                           break;
                                   }
                                   count++;
                           }
                             else if(s[k]=='D')
                           {
                                   row++;
                                   if(row>=n)
                                   {
                                           break;
                                   }
                                   count++;
                           }
                             else if(s[k]=='U')
                           {
                                   row--;
                                   if(row<0)
                                   {
                                           break;
                                   }
                                   count++;
                           }
                            k++;
                    }
                   res.push_back(count); 
            }
            return res;
            
    }
};