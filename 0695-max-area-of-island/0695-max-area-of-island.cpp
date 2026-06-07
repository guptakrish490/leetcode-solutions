class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& vis, vector<vector<int>>& grid, int& area){
        int m=grid.size(); int n=grid[0].size();

        vis[r][c]=1;

        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,1,-1};

        for(int k=0;k<4;k++){
            int nr=r+dr[k];
            int nc=c+dc[k];

            if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc]){
                area++;
                dfs(nr,nc,vis,grid,area);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(); int n=grid[0].size();

        int maxArea=0;

        vector<vector<int>>vis(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j] && !vis[i][j]){
                    int area=1;
                    
                    dfs(i,j,vis,grid,area);
                    maxArea=max(maxArea,area);
                }
            }
        }

        return maxArea;
    }
};