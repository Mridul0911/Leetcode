class LFUCache {
public:
    int cap;
    map<int,list<vector<int> >::iterator> mpKey,mpCnt;
    list<vector<int> > dll;
    LFUCache(int capacity) {
        this->cap=capacity;
    }

    void printDll() {
        for(auto &i:dll) {
            cout<<"("<<i[0]<<" "<<i[1]<<" "<<i[2]<<") , ";
        }
        cout<<endl;
    }
    void printMpKey() {
        for(auto &i:mpKey) {
            cout<<i.first<<" - "<<"("<<((*i.second)[0])<<" "<<((*i.second)[1])<<" "<<((*i.second)[2])<<")"<<endl;;
        }
        cout<<"+"<<endl;;
    }
        void printMpCnt() {
        for(auto &i:mpCnt) {
            cout<<i.first<<" - "<<"("<<((*i.second)[0])<<" "<<((*i.second)[1])<<" "<<((*i.second)[2])<<")"<<endl;;
        }
    }

    int get(int key) {
        if(cap==0) return -1;
        // cout<<key<<endl;
        if(mpKey.find(key)==mpKey.end()) return -1;
        auto itr=mpKey[key];
        vector<int> box=*itr;
        int val=box[1];
        auto itr2=itr;
        auto itr3=itr;
        auto itr4=mpCnt[box[2]];
        bool prev=false;
        if(itr4!=dll.begin()) {
            itr4--;
            prev=true;
        }
        
        if(itr==mpCnt[box[2]]) {
            mpCnt.erase(box[2]);
            if((++itr3)!=dll.end()&&(((*itr3)[2])==box[2])) {
                mpCnt[box[2]]=itr3;
            }
        }
        dll.erase(itr);
        box[2]++;
        if(!prev) {
            // cout<<"BSR "<<key<<endl;
            dll.insert(dll.begin(),box);
            mpCnt[box[2]]=dll.begin();
            mpKey[key]=dll.begin();
        }
        else {
            if(mpCnt.find(box[2])!=mpCnt.end()) {
                auto itr5=mpCnt[box[2]];
                dll.insert(itr5,box);
                itr5--;
                mpKey[key]=itr5;
                mpCnt[box[2]]=itr5;
            }
            else {
                itr4++;
                dll.insert(itr4,box);
                itr4--;
                mpKey[key]=itr4;
                mpCnt[box[2]]=itr4;
            }
        }
        // printDll();
        // printMpKey();
        // printMpCnt();
        return val;
    }
    
    void put(int ke, int value) {
        if(cap==0) return ;
        // cout<<ke<<" "<<value<<endl;
        if(mpKey.find(ke)!=mpKey.end()) {
            (*mpKey[ke])[1]=value;
            get(ke);
        }
        else {
            if(dll.size()==cap) {
                int key=(*dll.rbegin())[0];
                int cnt=(*dll.rbegin())[2];
                auto itr=mpKey[key];
                if(itr==mpCnt[cnt]) {
                    mpCnt.erase(cnt);
                }
                mpKey.erase(key);
                dll.erase(itr);
            } 
            vector<int> box(3);
            box[0]=ke; box[1]=value; box[2]=1;
            if(mpCnt.find(1)!=mpCnt.end()) {
                auto itr2=mpCnt[1];
                dll.insert(itr2,box);
                itr2--;
                mpKey[ke]=itr2;
                mpCnt[1]=itr2;
            }
            else {
                dll.insert(dll.end(),box);
                auto itr3=(--dll.end());
                mpKey[ke]=itr3;
                mpCnt[1]=itr3;
            }
        }
        // printDll();
        // printMpKey();
        // printMpCnt();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */