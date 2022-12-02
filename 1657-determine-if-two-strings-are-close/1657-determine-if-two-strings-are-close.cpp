class Solution {
public:
    bool closeStrings(string word1, string word2) 
    {
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        set<char> s1;
        set<char> s2;
        for(auto i:word1)
        {
            freq1[i-'a']++;
            s1.insert(i);
        }
        for(auto i:word2)
        {
            freq2[i-'a']++;
            s2.insert(i);
        }
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
        return ((freq1==freq2) && (s1==s2));
    }
};