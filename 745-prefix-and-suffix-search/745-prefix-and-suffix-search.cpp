class WordFilter {
   private:
    unordered_map<string, int> hashMap;

   public:
    WordFilter(vector<string>& words) {
             ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
        int n = words.size();
        for (int i = 0; i < n; i++) {
            string word = words[i];
            int wordSize = word.size();
            for (int j = 1; j <= wordSize; j++) {
                string p = word.substr(0, j);
                for (int k = 0; k < wordSize; k++) {
                    string s = word.substr(k, wordSize);
                    hashMap[p + "|" + s] = i + 1;
                }
            }
        }
    }

    int f(string prefix, string suffix) {
             ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
        string s = prefix + "|" + suffix;
        return hashMap[s]-1;
    }
};