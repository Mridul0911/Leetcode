class Solution {
public:
        void find(long long num,int n,int k,vector<int> &ans)
        {
              if(n==0)  
              {
                    ans.push_back(num);
                    return;
              }
              int start;
                if(num==0)
                {
                        start=1;
                }
                else
                {
                        start=0;
                }
                for(int i=start;i<10;i++)
                {
                     if(num and abs(i-num%10)!=k) continue;
                        num*=10;
                        num+=i;
                        find(num,n-1,k,ans);
                        num=num/10;
                }
        }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
            long long num=0;
            find(num,n,k,ans);
                return ans;
    }
};