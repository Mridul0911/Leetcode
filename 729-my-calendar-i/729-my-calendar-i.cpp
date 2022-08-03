class MyCalendar {
public:
    vector<pair<int,int>> inp;
    MyCalendar() {
    }
    bool book(int start, int end){
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