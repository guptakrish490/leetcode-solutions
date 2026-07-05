class Solution {
public:
    bool dfs(int curr, int r, int c, vector<vector<char>>& board, string word,
             vector<vector<int>>& vis) {
        if (curr == word.size())
            return true;

        int m = board.size();
        int n = board[0].size();

        if (r < 0 || r >= m || c < 0 || c >= n)
            return false;
        if (vis[r][c] || board[r][c] != word[curr])
            return false;

        vis[r][c] = 1;

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (dfs(curr + 1, nr, nc, board, word, vis))
                return true;
        }

        vis[r][c] = 0;

        return false;
    }


    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && board[i][j] == word[0]) {
                    if (dfs(0, i, j, board, word, vis))
                        return true;
                }
            }
        }

        return false;
    }
};