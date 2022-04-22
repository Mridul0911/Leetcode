class MyHashMap {
public:
     vector<pair<int,int>> hash;
        
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
         remove(key); // if value already exist in a hash 
        hash.push_back({key,value});
    }
    
    int get(int key) {
         for(auto it:hash)
         {
                 if(it.first==key)
                 {
                         return it.second;
                 }
         }
            return -1;
    }
    
    void remove(int key) {
       int removablekey=get(key);
            if(removablekey!=-1)
            {
                    vector<pair<int,int>> :: iterator it;
              for(it = hash.begin(); it != hash.end(); it++){
                            if(it->first==key)
                            {
                                    hash.erase(it);
                                    return;
                            }
                    }
            }
           
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */