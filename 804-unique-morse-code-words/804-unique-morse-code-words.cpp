class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) \
    {
  vector<string> codes = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> ans;
        for(auto it:words)
        {
            string curr="";
            for(auto ch:it)
            {
                curr+=codes[ch-97];
            }
            ans.insert(curr);
        }
        return ans.size();
     }
};