class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, int>> q;

        int freshCnt=0;


        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(grid[i][j]==1) freshCnt++;
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        if(freshCnt==0) return 0;
        if(freshCnt>0 && q.empty()) return -1;

        int minutes=-1;

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        
        while(!q.empty()){
            int size=q.size();
            minutes++;

            for(int i=0;i<size;i++){
                pair<int,int> p=q.front(); q.pop();

                for(int k=0;k<4;k++){
                    int nr=p.first+dr[k];
                    int nc=p.second+dc[k];

                    if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc]==1){
                        freshCnt--;
                        grid[nr][nc]=2;
                        vis[nr][nc]=1;
                        q.push({nr,nc});
                    }
                }
            }
        }

        return freshCnt==0? minutes:-1;
            
    }
};