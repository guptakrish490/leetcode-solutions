class Solution {
public:
    void dfs(int r, int c, int& newColor, int& prevColor, vector<vector<int>>& image,
             vector<vector<int>>& vis) {

        int m = image.size();
        int n = image[0].size();

        vis[r][c] = 1;
        image[r][c] = newColor;

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n && image[nr][nc]==prevColor && !vis[nr][nc]) {
                dfs(nr, nc, newColor, prevColor, image, vis);
            }
        }
    }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int m = image.size();
        int n = image[0].size();

        int prevColor=image[sr][sc];

        vector<vector<int>> vis(m, vector<int>(n, 0));
        dfs(sr,sc,color,prevColor,image,vis);

        return image;
    }
};