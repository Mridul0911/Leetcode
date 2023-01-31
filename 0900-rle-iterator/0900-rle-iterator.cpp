class RLEIterator {
public:
        vector<int> inp;
        
    RLEIterator(vector<int>& encoding) {
        inp=encoding;
    }
    
    int next(int n) {
        for(int i=0;i<inp.size();i+=2)
        {
                if(n<=inp[i])
                {
                        inp[i]-=n;
                        return inp[i+1];
                }
                else
                {
                        n-=inp[i];
                        inp[i]=0;
                }
        }
         return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */