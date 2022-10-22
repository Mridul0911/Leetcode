class Solution {
public:
    string minWindow(string s, string t) {
          int i=0,j=0;
       int len=INT_MAX;
          int startIdx = 0;
          string result;
        unordered_map<char,int> mp;
        for(int i=0 ; i<t.length();i++ )
         mp[t[i]]++;
        int count=mp.size(); 
    while(j<s.length())
    {
       if(mp.find(s[j])!=mp.end())
       {
           mp[s[j]]--;
               cout<<mp[s[j]]<<" "<<s[j]<<endl;
           if(mp[s[j]]==0)
           count--;
       }
       if(count>0) 
       j++;
       else if(count==0) 
       {  
           if(j-i+1 < len) 
           {
               len=min(len,j-i+1); 
               startIdx = i;
               result = s.substr(startIdx,len);
           }
           while(count==0)
           {
               if(mp.find(s[i])==mp.end()) 
               {
                  i++;
                   
                  if(j-i+1 < len)
                   {
                       len=min(len,j-i+1); 
                       startIdx = i;
                       result = s.substr(startIdx,len);
                   }
               }
               else
               {
                   mp[s[i]]++;
                   if(mp[s[i]]==1) 
                   {
                       i++;
                       count++;
                   }
                   else 
                   {  
                       i++;
                       if(j-i+1 < len)  
                       {
                           len=min(len,j-i+1); 
                           startIdx = i;
                           result = s.substr(startIdx,len);
                       }
                   }
               }
           }
           j++; 
       }
    }
        return (len==INT_MAX ? "":result);
    }
};