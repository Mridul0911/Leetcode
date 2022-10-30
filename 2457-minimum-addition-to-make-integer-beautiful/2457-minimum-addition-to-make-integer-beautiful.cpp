class Solution {
public:
    int sumDigits(long long n){
        long long int temp=0;
        while(n){
            temp += n%10;
            n /= 10;
        }
        return temp;
    }
    long long makeIntegerBeautiful(long long n, int target) {
        long long int  x=target;
        
        while(x<n){
            x=x*10;
        }
        x = x-n;
        long long int i=0;
         long long int m=0;
        while( sumDigits(n+m) > target && m != x){
            i++;
            long long int temp = pow(10, i);
            m =  x % temp;  
        }
        return m;
    }
};