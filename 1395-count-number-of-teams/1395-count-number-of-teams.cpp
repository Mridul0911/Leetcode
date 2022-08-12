class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans=0;
            int n=rating.size();
            for(int i=0;i<n;i++)
            {
                    int leftLarge=0;
                    int leftLess=0;
                    int rightLarge=0;
                    int rightLess=0;
                    for(int j=i-1;j>=0;j--)
                    {
                            if(rating[j]>rating[i])
                            {
                                    leftLarge++;
                            }
                            else
                            {
                                    leftLess++;
                            }
                    }
                    for(int j=i+1;j<rating.size();j++)
                    {
                            if(rating[j]>rating[i])
                            {
                                    rightLarge++;
                            }
                            else
                            {
                                    rightLess++;
                            }
                    }
                    ans+=(leftLarge*rightLess+leftLess*rightLarge);
            }
            return ans;
    }
};