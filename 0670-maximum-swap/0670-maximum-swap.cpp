class Solution {
public:
    int maximumSwap(int num) {
        string val=to_string(num);
        int n=val.size();
        int maxi=n-1;
        int p1=0;
        int p2=0;
        for(int i=n-2;i>=0;i--){
            if(val[maxi]>val[i]){
                p1=maxi,p2=i;
            }
            if(val[i]>val[maxi]) maxi=i;
        }
        swap(val[p1],val[p2]);
        return stoi(val);
    }
};