class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x=abs(fx-sx);
        int y=abs(sy-fy);
        if(x==0 && y==0 && t==1) return false;
        int ans=min(x,y);
        if(ans+abs(x-y)<=t)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};