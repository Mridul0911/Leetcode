class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> st(J.begin(), J.end());
        int c=0;
        for(char i:S) 
            c+=st.count(i);
        
        return c;
        
    }
};