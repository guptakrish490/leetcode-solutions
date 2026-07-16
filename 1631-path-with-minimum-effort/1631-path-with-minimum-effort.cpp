class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        vector<vector<int>> efforts(m, vector<int>(n, 1e9));

        efforts[0][0] = 0;
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            auto [effort, row, col] = pq.top();
            pq.pop();

            if (row == m - 1 && col == n - 1)
                return effort;

            int dr[4] = {-1, 1, 0, 0};
            int dc[4] = {0, 0, 1, -1};

            for (int i = 0; i < 4; i++) {
                int nr = row + dr[i];
                int nc = col + dc[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int diff = abs(heights[row][col] - heights[nr][nc]);
                    int maxEffort = max(diff, effort);

                    if (efforts[nr][nc] > maxEffort) {
                        efforts[nr][nc] = maxEffort;
                        pq.push({maxEffort, nr, nc});
                    }
                }
            }
        }

        return 0;
    }
};