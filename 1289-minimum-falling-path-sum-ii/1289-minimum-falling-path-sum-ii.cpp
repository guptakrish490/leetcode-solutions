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
        vector<int> prev(n, 0);

        for (int i = 0; i < n; i++) {
            prev[i] = grid[0][i];
        }

        int minPathSum = 1e9;

        for (int i = 1; i < n; i++) {
            vector<int> curr(n);
            int min1 = INT_MAX, min2 = INT_MAX, minIdx = -1;

            for (int j = 0; j < n; j++) {
                if (prev[j] < min1) {
                    min2 = min1;
                    min1 = prev[j];
                    minIdx = j;
                } else if (prev[j] < min2) {
                    min2 = prev[j];
                }
            }

            for (int j = 0; j < n; j++) {
                if (minIdx == j)
                    curr[j] = min2;
                else
                    curr[j] = min1;

                curr[j] += grid[i][j];
            }

            prev = curr;
        }

        for (int i = 0; i < n; i++) {
            minPathSum = min(minPathSum, prev[i]);
        }

        return minPathSum;
    }
};