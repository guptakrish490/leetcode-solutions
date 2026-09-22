class Solution {
public:
    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int n = grid.size();

        if (j < 0 || j >= n)
            return 1e9;
        if (i == 0)
            return grid[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];

        int minPath = 1e9;
        for (int k = 0; k < n; k++) {
            if(k==j) continue;
            minPath = min(minPath, f(i - 1, k, grid, dp));
        }

        return dp[i][j] = grid[i][j] + minPath;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        int minPathSum = 1e9;
        for (int j = 0; j < n; j++) {
            minPathSum = min(minPathSum, f(n - 1, j, grid, dp));
        }

        return minPathSum;
    }
};