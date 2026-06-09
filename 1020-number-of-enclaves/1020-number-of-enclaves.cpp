class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& vis, vector<vector<int>>& grid){
        int m=grid.size(); int n=grid[0].size();

        vis[r][c]=1;

        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,1,-1};

        for(int k=0;k<4;k++){
            int nr=r+dr[k];
            int nc=c+dc[k];

            if(nr>=0 && nr<m && nc>=0 && nc<n && ! vis[nr][nc] && grid[nr][nc]){
                dfs(nr,nc,vis,grid);
            }
        }

    }


    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size(); int n=grid[0].size();

        vector<vector<int>>vis(m, vector<int>(n,0));
        int cnt=0;

        for(int j=0;j<n;j++){
            if(!vis[0][j] && grid[0][j]) dfs(0,j,vis,grid);
            if(!vis[m-1][j] && grid[m-1][j]) dfs(m-1,j,vis,grid);
        }
        for(int i=0;i<m;i++){
            if(!vis[i][0] && grid[i][0]) dfs(i,0,vis,grid);
            if(!vis[i][n-1] && grid[i][n-1]) dfs(i,n-1,vis,grid);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]) cnt++;
            }
        }

        return cnt;
    }
};