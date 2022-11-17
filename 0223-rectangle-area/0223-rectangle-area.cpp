class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2){
         int area1=(ax2-ax1)*(ay2-ay1);
            int area2=(bx2-bx1)*(by2-by1);
            int overlapx=min(bx2,ax2)-max(ax1,bx1);
            int overlapy=min(by2,ay2)-max(ay1,by1);
            int overlaparea=0;
            if(overlapx>0 && overlapy>0)
            {
                    overlaparea=overlapx*overlapy;
            }
            return area1+area2-overlaparea;
            }
};