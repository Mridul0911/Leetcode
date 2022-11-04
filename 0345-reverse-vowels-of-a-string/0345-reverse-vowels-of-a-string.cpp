class Solution {
public:
    unordered_set<char>st{'a','e','i','o','u','A','E','I','O','U'};
    string reverseVowels(string s) {
        int n=s.size();
        int i=0,j=n-1;
        while(i<n&&j>=0&&i<j)
        {
            while(i<n&&!st.count(s[i]))
                i++;
            while(j>=0&&!st.count(s[j]))
                j--;
            if(i<j)
            {
                char c= s[i];
                s[i]=s[j];
                s[j]=c;
                i++;
                j--;
            }
        }
        return s;
        
        
    }
};