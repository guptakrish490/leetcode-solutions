class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        int minPathSum = 1e9;
        for (int i = 0; i < n; i++) {
            dp[0][i] = matrix[0][i];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int minPath=1e9;

                dp[i][j] = matrix[i][j];

                minPath = min(minPath, dp[i - 1][j]);
                if (j > 0)
                    minPath = min(dp[i - 1][j - 1], minPath);
                if (j < n - 1)
                    minPath = min(dp[i - 1][j + 1], minPath);

                dp[i][j] += minPath;
            }
        }

        for (int i = 0; i < n; i++) {
            minPathSum = min(minPathSum, dp[n - 1][i]);
        }

        return minPathSum;
    }
};