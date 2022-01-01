class Solution {
public:
    int romanToInt(string s) 
    {
        unordered_map<char, int> ans = { { 'I' , 1 },
                                   { 'V' , 5 },
                                   { 'X' , 10 },
                                   { 'L' , 50 },
                                   { 'C' , 100 },
                                   { 'D' , 500 },
                                   { 'M' , 1000 } };
      
        
   int sum = ans[s[s.length()-1]];
   for (int i = s.length() - 2; i >= 0; i--) 
   {
           
       if(ans[s[i]]<ans[s[i+1]])
       {
           sum -= ans[s[i]];
       }
       else
       {
           sum += ans[s[i]];
       }
   }
   
   return sum;
    }
};