class Solution {
public:
    int arrangeCoins(int n) {
        int left=1;
        long long int right=(long)n+1;
        while(left<right){
            int mid=left + (right-left)/2;
            if(mid*1ll*(mid+1)/2 > n) right=mid;
            else left=mid+1;
        }
        return right-1;
    }
};