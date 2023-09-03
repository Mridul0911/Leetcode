class Solution {
public:
    struct Grid {
        vector<vector<int>> dp;
        int m, n;

        Grid(int rows, int cols) : m(rows), n(cols), dp(rows, vector<int>(cols, -1)) {
        }
        int solve(int i, int j) {
            if (i == 0 && j == 0) {
                return 1;
            }
            if (i < 0 || j < 0) {
                return 0;
            }
            if (dp[i][j] != -1) {
                return dp[i][j];
            }
            int up = solve(i - 1, j);
            int down = solve(i, j - 1);
            return dp[i][j] = up + down;
        }

        int uniquePaths() {
            return solve(m - 1, n - 1);
        }
    };
    int uniquePaths(int m, int n) {
        Grid grid(m, n);
        return grid.uniquePaths();
    }
};
