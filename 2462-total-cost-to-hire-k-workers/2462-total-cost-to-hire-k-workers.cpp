class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int,vector<int>,greater<int>> pq1,pq2;
            int count=0;
            long long int ans=0;
            int i=0;
            int j=costs.size()-1;
         while(count<k)
         {
         //        cout<<i<<endl;
                 while(pq1.size()<candidates && i<j)
                 {
                         pq1.push(costs[i]);
                         i++;
                 }
                 while(pq2.size()<candidates && j>=i)
                 {
                         pq2.push(costs[j]);
                         j--;
                 }
               //  cout<<pq1.size()<<" "<<pq2.size()<<endl;
           //      cout<<endl;
                 int x;
                 if(pq1.size()>0)
                 {
                         x=pq1.top();
                 }
                 else
                 {
                         x=INT_MAX;
                 }
                 int y;
                 if(pq2.size()>0)
                 {
                       y=pq2.top();
                 }
                 else
                 {
                       y=INT_MAX;
                 }
                // cout<<x<<" "<<y<<endl;
                 if(x<=y)
                 {
                         ans+=x;
                         pq1.pop();
                 }
                 else
                 {
                         ans+=y;
                         pq2.pop();
                 }
                 count++;
         }
            return ans;
    }
};