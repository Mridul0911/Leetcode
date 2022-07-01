class Solution {
public:   
        bool isPossible(vector<int> &weights,int days,int capacity)
        {
                int sum=0;
                int days_req=0;
                for(int i=0;i<weights.size();i++)
                {
                        if(weights[i]>capacity)
                        {
                                return false;
                        }
                        sum+=weights[i];
                        if(sum>=capacity)
                        {
                                if(sum>capacity)
                                {
                                        i--;
                                }
                                sum=0;
                                days_req++;
                        }
                }
                if(sum>0 && sum<capacity)
                {
                        days_req++;
                }
                return days_req<=days;
        }
    int shipWithinDays(vector<int>& weights, int days) {
             ios_base::sync_with_stdio(0);
             cin.tie(0); cout.tie(0);
           int max_capacity=0;
            for(int i=0;i<weights.size();i++)
            {
                    max_capacity+=weights[i];
            }
            int min_capacity=1;
            while(min_capacity<=max_capacity)
            {
                    int mid=(min_capacity+max_capacity)/2;
                    if(isPossible(weights,days,mid))
                    {
                            max_capacity=mid-1;
                    }
                    else
                    {
                            min_capacity=mid+1;
                    }
            }
            return min_capacity;
     }
};
