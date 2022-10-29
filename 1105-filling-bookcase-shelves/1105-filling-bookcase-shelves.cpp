class Solution {
public:
        int find(vector<vector<int>> &books,int shelfWidth,int n,vector<int> &dp)
        {
                if(n==0)
                {
                        return 0;
                }
                if(dp[n]!=-1)
                {
                        return dp[n];
                }
                int sum=0;
                int maxi=0;
                int mini=INT_MAX;
                for(int i=n-1;i>=0;i--)
                {
                        if(sum+books[i][0]<=shelfWidth)
                        {
                                sum+=books[i][0];
                                maxi=max(maxi,books[i][1]);
                                mini=min(mini,maxi+find(books,shelfWidth,i,dp));
                        }
                        else
                        {
                                break;
                        }
                }
                return dp[n]=mini;
        }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
            vector<int> dp(n+1,-1);
        return find(books,shelfWidth,n,dp);
    }
};