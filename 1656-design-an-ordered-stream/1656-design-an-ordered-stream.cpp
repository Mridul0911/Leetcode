class OrderedStream {
public:
    set<pair<int,string>>s;
    int start=0;
    OrderedStream(int n) {
        
    }
    
    vector<string> insert(int idKey, string value) {
        s.insert({idKey,value});
        vector<string>ans;
        while(s.size() && s.begin()->first==start+1){
            ans.push_back(s.begin()->second);
            s.erase(s.begin());
            start++;
        }
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */