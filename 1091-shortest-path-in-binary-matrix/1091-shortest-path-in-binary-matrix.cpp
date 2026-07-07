class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int V = grid.size();
        if (grid[0][0] || grid[V - 1][V - 1])
            return -1;

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        vector<vector<int>> dist(V, vector<int>(V, 1e9));

        dist[0][0] = 1;
        pq.push({1, {0, 0}});

        while (!pq.empty()) {
            auto top = pq.top();
            int dis = top.first;
            int r = top.second.first;
            int c = top.second.second;
            pq.pop();

            if (r == V - 1 && c == V - 1)
                return dis;

            int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
            int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

            for (int i = 0; i < 8; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < V && nc >= 0 && nc < V && !grid[nr][nc]) {
                    if (dist[nr][nc] > dis + 1) {
                        dist[nr][nc] = dis + 1;
                        pq.push({dist[nr][nc], {nr, nc}});
                    }
                }
            }
        }

        return (dist[V - 1][V - 1] == 1e9) ? -1 : dist[V - 1][V - 1];
    }
};