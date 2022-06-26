class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
    int sum=0;
            int n=cardPoints.size();
            for(int i=0;i<k;i++)
            {
                    sum+=cardPoints[i];
            }
            int curr=sum;
            for(int i=k-1;i>=0;i--)
            {
                   curr-=cardPoints[i];
                   curr+=cardPoints[n-k+i];
                    sum=max(sum,curr);
            }
            return sum;
          }
};