class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int x=__gcd(str1.size(),str2.size());
        if(str1+str2==str2+str1)
        {
        if(str1.size()>str2.size())
        {
            return str1.substr(0,x);
        }
        else
        {
            return str2.substr(0,x);
        }
        }
        else
        {
            return "";
        }
    }
};