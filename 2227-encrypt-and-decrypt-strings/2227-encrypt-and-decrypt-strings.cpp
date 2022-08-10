class Encrypter {
public:
       map<char,string> mp1;
        map<string,int> mp2;
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
       int n=keys.size();
            for(int i=0;i<n;i++)
            {
                mp1[keys[i]]=values[i];
            }
            for(auto it:dictionary)
            {
                    auto e=encrypt(it);
                    if(e.size())mp2[encrypt(it)]++;
            }
   }
    string encrypt(string word1){
       string ans="";
            for(auto gg:word1)
            {
                    if(mp1.count(gg)==0)return ""; 
                    ans+=mp1[gg];
            }
            return ans;
    }
    int decrypt(string word2) {
       return mp2.count(word2)?mp2[word2]:0;
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2); */