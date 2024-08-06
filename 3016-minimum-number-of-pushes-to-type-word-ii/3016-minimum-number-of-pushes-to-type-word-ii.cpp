class Solution {
public:
    int minimumPushes(string word) {
        int ans=0;
        vector<int> freq(26,0);
        for(auto it:word)
        {
            freq[it-'a']++;
        }
        sort(freq.begin(),freq.end(),greater<int>());
        for(int i=0;i<26;i++)
        {
            ans+=freq[i]*((i/8)+1);
        }
        return ans;
    }
};