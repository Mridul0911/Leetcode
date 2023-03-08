class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
           sort(piles.begin(),piles.end());
            int k=1;
            int start=1;
            int end=piles[piles.size()-1];
       while(start<=end)
       {
               int k=(start+end)/2;
               double sum=0;
               for(int i=0;i<piles.size();i++)
               {
                       double gg=piles[i];
                       sum=sum+ceil(gg/k);
               }
               if(sum>h)
               {
                       start=k+1;
               }
               else if(sum<=h)
               {
                       end=k-1;
               }
              // cout<<start<<" "<<end<<endl;
        }
              return start;
    }
};