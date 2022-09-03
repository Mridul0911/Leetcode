class Solution {
public:
    int halveArray(vector<int>& nums) {
       priority_queue<double> pq;
            double sum=0;
            for(auto it:nums)
            {
                    sum+=it;
                    pq.push(it);
            }
            double goal=sum/2;
            int count=0;
            while(sum>goal)
            {
                    double num=pq.top();
                    pq.pop();
                    sum-=num/2;
                    pq.push(num/2);
                    count++;
            }
            return count;
    }
};