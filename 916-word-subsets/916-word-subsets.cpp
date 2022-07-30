class Solution {
public:
    unordered_map<char,int> getFreqMap(string s){
        unordered_map<char,int> freq;
        for(char ch : s)
            freq[ch]++;
        return freq;
    }
    bool isSubset(unordered_map<char,int>b, unordered_map<char,int> a){
        for(auto entry : b){
            if(entry.second > a[entry.first])
                return false;
        }
        return true;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>res;
        unordered_map<char,int> freq;
        for(string word2 : words2){
            vector<int> temp(26, 0);
            for(char ch : word2){
                temp[ch-'a']++;
                freq[ch] = max(freq[ch], temp[ch-'a']);
            }
        }
        
        for(string word1: words1){
            unordered_map<char,int> word1_freq = getFreqMap(word1);
            bool flag = true;
            if(isSubset(freq, word1_freq))
                res.push_back(word1);
        }
        return res;
    }
};
