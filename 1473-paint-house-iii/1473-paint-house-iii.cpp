class Solution
{
public:
    int minCost(vector<int> &houses, vector<vector<int>> &cost, int m, int n, int target)
    {
        vector<vector<vector<long long int>>> dp(105, vector<vector<long long int>>(105, vector<long long int>(25, 1000001)));
        for (int color = 1; color <= n; color++)
        {
            if (houses[0] == color)
            {
                dp[0][1][color - 1] = 0;
            }
            else if (!houses[0])
                dp[0][1][color - 1] = cost[0][color - 1];
        }
        for (int house = 1; house < m; house++)
        {
            for (int neighbour = 1; neighbour <= min(target, house + 1); neighbour++)
            {
                for (int color = 1; color <= n; color++)
                {
                    if (houses[house] && houses[house] != color)
                        continue;
                    long long int costToPaint = (houses[house] == 0) ? (cost[house][color - 1]) : (0);
                    for (int prevcolor = 1; prevcolor <= n; prevcolor++)
                    {
                        if (color == prevcolor)
                        {
                            dp[house][neighbour][color-1] = min(dp[house][neighbour][color-1], costToPaint + dp[house - 1][neighbour][color - 1]);
                        }
                        else
                        {
                            dp[house][neighbour][color-1] = min(dp[house][neighbour][color-1], costToPaint + dp[house - 1][neighbour - 1][prevcolor - 1]);
                        }
                    }
                }
            }
        }
       long long int ans = 1000001;
        for (int i = 1; i <= n; i++)
        {
            ans = min(ans, dp[m - 1][target][i - 1]);
            cout << ans << " ";
        }
        return ans == 1000001 ? -1 : ans;
    }
};