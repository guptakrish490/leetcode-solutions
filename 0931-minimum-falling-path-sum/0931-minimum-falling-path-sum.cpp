class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n, 0);

        int minPathSum = 1e9;
        for (int i = 0; i < n; i++) {
            prev[i] = matrix[0][i];
        }

        for (int i = 1; i < n; i++) {
            vector<int> curr(n);
            for (int j = 0; j < n; j++) {
                int minPath=1e9;

                curr[j] = matrix[i][j];

                minPath = min(minPath, prev[j]);
                if (j > 0)
                    minPath = min(prev[j - 1], minPath);
                if (j < n - 1)
                    minPath = min(prev[j + 1], minPath);

                curr[j] += minPath;
            }

            prev=curr;
        }

        for (int i = 0; i < n; i++) {
            minPathSum = min(minPathSum, prev[i]);
        }

        return minPathSum;
    }
};