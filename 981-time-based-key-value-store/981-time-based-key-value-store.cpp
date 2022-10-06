class TimeMap {
public:
    unordered_map<string,unordered_map<int,string>>m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
         m[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        if(!m.count(key))
            return"";
        for(int i=timestamp;i>=1;i--)
            if(m[key].count(i))
                return m[key][i];
        return "";
    }
};