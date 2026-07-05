class Solution {
public:
    int bfs(int r, int c, vector<vector<int>>& grid, int n) {
        vector<vector<int>> dist(n, (vector<int>(n, -1)));
        queue<pair<int, int>> q;

        int dr[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dc[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

        dist[r][c] = 1;
        q.push({r, c});

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            if (row == n - 1 && col == n - 1)
                return dist[row][col];

            for (int i = 0; i < 8; i++) {
                int nr = row + dr[i];
                int nc = col + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !grid[nr][nc] &&
                    dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[row][col] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return -1;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        int ans = bfs(0, 0, grid, n);

        return ans;
    }
};