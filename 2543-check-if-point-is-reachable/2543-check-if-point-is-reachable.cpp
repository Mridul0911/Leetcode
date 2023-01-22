class Solution {
public:
        bool find(int a, int b)
        {
                int g=__gcd(a,b);
             while(g%2==0)
             {
                     g=g/2;
             }
                return g==1;
        }
    bool isReachable(int targetX, int targetY) {
       return find(targetX,targetY);
    }
};