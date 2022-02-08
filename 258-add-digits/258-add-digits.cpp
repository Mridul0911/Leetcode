class Solution {
public:
    int addDigits(int num) {
            
        while(1)
        {
            int sum=0;
                while(num!=0)
                {
                        sum+=num%10;
                        num=num/10;
                }
                num=sum;
                if(num<10)
                {
                        return sum;
                }
                
        }
            return -1;
            
    }
};