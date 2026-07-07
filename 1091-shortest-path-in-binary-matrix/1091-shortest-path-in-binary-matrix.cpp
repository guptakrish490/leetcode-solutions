class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int V = grid.size();
        if (grid[0][0] || grid[V - 1][V - 1])
            return -1;

        queue<pair<int,int>>q;
        vector<vector<int>> dist(V, vector<int>(V, 1e9));

        dist[0][0] = 1;
        q.push({0, 0});

        int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!q.empty()) {
            auto [r,c]=q.front();
            q.pop();

            if (r == V - 1 && c == V - 1)
                return dist[r][c];

            for (int i = 0; i < 8; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < V && nc >= 0 && nc < V && !grid[nr][nc]) {
                    if (dist[nr][nc] > dist[r][c] + 1) {
                        dist[nr][nc] = dist[r][c] + 1;
                        q.push({nr, nc});
                    }
                }
            }
        }

        return (dist[V - 1][V - 1] == 1e9) ? -1 : dist[V - 1][V - 1];
    }
};