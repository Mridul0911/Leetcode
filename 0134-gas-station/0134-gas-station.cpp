class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
      int totalgain=0;
            int fuel=0;
            int ans=0;
            for(int i=0;i<gas.size();i++)
            {
                    fuel+=(gas[i]-cost[i]);
                    totalgain+=(gas[i]-cost[i]);
                    if(fuel<0)
                    {
                            ans=i+1;
                            fuel=0;
                    }
            }
            if(totalgain>=0)
            {
                    return ans;
            }
            else
            {
                    return -1;
            }
    }
};