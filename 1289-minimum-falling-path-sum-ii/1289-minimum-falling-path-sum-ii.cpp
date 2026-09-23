class Solution {
public:
    int secondMini(vector<int>& arr, int minIdx) {
        int n = arr.size();

        int firstMin = 1e9;

        for (int i = 0; i < n; i++) {
            if (arr[i] < firstMin) {
                firstMin = arr[i];
                minIdx = i;
            }
        }

        int secondMin = 1e9;

        for (int j = 0; j < n; j++) {
            if (j == minIdx)
                continue;
            secondMin = min(secondMin, arr[j]);
        }

        return secondMin;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++) {
            dp[0][i] = grid[0][i];
        }

        int minPathSum = 1e9;

        for (int i = 1; i < n; i++) {
            int min1 = INT_MAX, min2 = INT_MAX, minIdx = -1;

            for (int j = 0; j < n; j++) {
                if (dp[i - 1][j] < min1) {
                    min2 = min1;
                    min1 = dp[i - 1][j];
                    minIdx = j;
                } else if (dp[i - 1][j] < min2) {
                    min2 = dp[i - 1][j];
                }
            }

            for (int j = 0; j < n; j++) {
                if (minIdx == j)
                    dp[i][j] = min2;
                else
                    dp[i][j] = min1;

                dp[i][j] += grid[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            minPathSum = min(minPathSum, dp[n - 1][i]);
        }

        return minPathSum;
    }
};