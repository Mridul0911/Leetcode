class Solution {
public:
     long long int findWays(int y)
     {
        if (y==1)
                return 4;
             int mod=1e9+7;
        long long int a=1;
        long long int b=1;
        long long int aa;
        long long int bb;
        for (int i=2; i<=y; i++)
	{
		aa = a;
		bb = b;
		b = (aa+ bb)%mod;
	   a = bb;
	}
        long long int ans=(a+b)%mod;
             
        long long int gg=(ans*ans)%mod;
             return gg;
}
 
    int countHousePlacements(int n) {
         int x=findWays(n)       ;
            return x;
    }
};