class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) 
    {
      int count=0;
            vector<int> res(60,0);
            for(int i=0;i<time.size();i++)
            {
                    int r=time[i]%60;
                    if(r==0)
                    {
                            count+=res[0];
                    }
                    else
                    {
                            count+=res[60-r];
                    }
                    res[r]++;
            }
            return count;
                  
                 
            
            
    }
};