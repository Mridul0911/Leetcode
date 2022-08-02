class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hh=(hour%12*30)+((double)minutes/60 * 30);
            cout<<hh<<endl;
        double m=minutes*6;
        double angle=abs(m - hh);
        if(angle>180) angle=360.0-angle;
        return angle;
    }
};