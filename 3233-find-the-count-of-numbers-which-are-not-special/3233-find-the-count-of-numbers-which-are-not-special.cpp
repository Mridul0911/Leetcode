class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int maxi=sqrt(r);
        vector<int> seieve(maxi+1,1);
        seieve[1]=0;
        for(int i=2;i<=maxi;i++)
        {
            if(seieve[i]==1)
            {
                for(int j=i*i;j<=maxi;j+=i)
                {
                    seieve[j]=0;
                }
            }
        }
        int cnt=0;
        for(int i=2;i<=maxi;i++)
        {
            if(seieve[i]==1)
            {
                int num=i*i;
                if(num>=l && num<=r)
                {
                    cnt++;
                }
            }
        }
        return (r-l+1)-cnt;
   }
};