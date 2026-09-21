class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> prev(n, 0);
        prev[0] = grid[0][0];

        for (int i = 0; i < m; i++) {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    curr[j] = prev[j];

                else {
                    int upSum = 1e9, leftSum = 1e9;

                    if (i > 0)
                        upSum = prev[j];
                    if (j > 0)
                        leftSum = curr[j - 1];

                    int minSum = min(upSum, leftSum);
                    curr[j] = minSum + grid[i][j];
                }
            }

            prev = curr;
        }

        return prev[n - 1];
    }
};