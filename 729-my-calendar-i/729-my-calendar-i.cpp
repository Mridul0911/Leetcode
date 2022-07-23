class MyCalendar {
public:
    vector<pair<int,int>> inp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        
           bool check=true;
            for(auto it:inp)
            {
                    if((start>= it.second || it.first>=end))continue;
                    check=false;
            }
            if(check)
            {
                    inp.push_back({start,end});
            }
            return check;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */