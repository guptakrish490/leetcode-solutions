class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    continue;

                int upSum = 1e9, leftSum = 1e9;
                
                if (i > 0)
                    upSum = dp[i - 1][j];
                if (j > 0)
                    leftSum = dp[i][j - 1];

                int minSum = min(upSum, leftSum);
                dp[i][j] = minSum + grid[i][j];
            }
        }

        return dp[m - 1][n - 1];
    }
};