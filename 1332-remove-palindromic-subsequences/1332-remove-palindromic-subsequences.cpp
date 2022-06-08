class Solution {
public:
    int removePalindromeSub(string s) {
        string g=s;
            reverse(g.begin(),g.end());
            if(s==g)
            {
                    return 1;
            }
            else
            {
                    return 2;
            }
            
            
    }
};