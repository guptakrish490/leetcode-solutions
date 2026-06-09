class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<pair<int,int>> q;


        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

    
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && ans[nr][nc] == -1) {
                    ans[nr][nc] = ans[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return ans;
    }
};
