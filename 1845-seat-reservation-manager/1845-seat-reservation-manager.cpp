class SeatManager {
public:
        set<int> s;
    SeatManager(int n) {
        for(int i=1;i<=n;i++)
        {
                s.insert(i);
        }
    }
    
    int reserve() {
        int it=*s.begin();
            s.erase(s.begin());
            return it;
    }
    void unreserve(int seatNumber) {
        s.insert(seatNumber);
    }
};