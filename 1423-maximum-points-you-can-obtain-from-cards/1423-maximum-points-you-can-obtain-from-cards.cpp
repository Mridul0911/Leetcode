class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
            for(int i=0;i<cardPoints.size();i++)
            {
                    sum+=cardPoints[i];
            }
            if(k==cardPoints.size())
            {
                    return sum;
            }
            int start=0;
            int end=0;
            int currSum=0;
            int maxi=INT_MIN;
            int n=cardPoints.size();
            int i=0;
            while(end<n)
            {
                 currSum+=cardPoints[end];
                    if((end-start+1)==(n-k))
                    {
                            maxi=max(maxi,sum-currSum);
                            currSum-=cardPoints[start];
                            start++;
                    }
                    end++;
            }
            return maxi;
}
};