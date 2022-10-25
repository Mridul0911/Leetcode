class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) 
    {
        string ans1="";
          string ans="";
          
      for(int i=0;i<word1.size();i++)
      {
          string s=word1[i];
          ans=ans+s;
      }
       for(int i=0;i<word2.size();i++)
      {
          string s=word2[i];
          ans1=ans1+s;
      } 
  if((ans.compare(ans1)) == 0) {
    return true;
   } 
        return false;
   
   }
};