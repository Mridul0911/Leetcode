class Solution {
public:
        string createString(vector<string> temp,int maxwidth)
        {
//             int numOfchar=0;
//                 for(auto it:temp)
//                 {
//                         numOfchar+=it.size();
//                 }
//                 int remaining=maxWidth-numOfchar;
//                 string ans="";
//                 if(remaining%(int)(temp.size()-1)==0)
//                 {
//                         int req=remaining/(temp.size()-1);
//                         for(auto it:temp)
//                         {
//                                 ans+=it;
//                                 for(int i=0;i<req;i++)
//                                 {
//                                         ans+=' ';
//                                 }
//                         }
//                         for(int i=0;i<req;i++)
//                         {
//                                         ans.pop_back();
//                         }
//                         return ans;
//                 }
//                 else
//                 {
                     
//                 }
               
                int numOfchar=0;
               for(auto it:temp)
                {
                        numOfchar+=it.size();
                }
                int remaining=maxwidth-numOfchar;
                string ans="";
                if(temp.size()==1)
                {
                        ans+=temp[0];
                        while(remaining--)
                        {
                                ans+=' ';
                        }
                        return ans;
                }
               int extraspace=remaining%(temp.size()-1);
                int required=remaining/(temp.size()-1);
                for(auto it:temp)
                {
                        ans+=it;
                        for(int i=0;i<required;i++)
                        {
                                ans+=' ';
                        }
                        if(extraspace)
                        {
                                ans+=' ';
                                extraspace--;
                        }
                }
                        for(int i=0;i<required;i++)
                        {
                                ans.pop_back();

                        }
                return ans;
        }
        string createlastline(vector<string> &temp,int maxwidth)
        {
                string ans="";
                for(auto it:temp)
                {
                        ans+=it;
                        ans+=' ';
                }
                ans.pop_back();
                int numOfchar=0;
               for(auto it:temp)
                {
                        numOfchar+=it.size();
                }
                int rem=(maxwidth-numOfchar-temp.size()+1);
                while(rem--)
                {
                        ans+=' ';
                }
                
                return ans;
        }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
           int len=0;
            vector<string> temp;
            for(auto it:words)
            {
                    if(len+it.size()+temp.size()>maxWidth)
                    {
                         ans.push_back(createString(temp,maxWidth));
                            temp.clear();
                            temp.push_back(it);
                            len=it.size();
                    }
                    else
                    {
                            temp.push_back(it);
                            len+=it.size();
                    }
            }
            ans.push_back(createlastline(temp,maxWidth));
            return ans;
            
    }
};