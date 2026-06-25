class Solution {
public:
    void traverse(int r, int c, vector<vector<int>>&vis, vector<vector<int>>& grid, int& area){
        int m=grid.size();
        int n=grid[0].size();

        vis[r][c]=1;
        area++;

        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,1,-1};

        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];

            if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc] && !vis[nr][nc]){
                traverse(nr,nc,vis,grid,area);
            }
        }
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));

        int maxArea=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j] && !vis[i][j]){
                    int area=0;
                    traverse(i,j,vis,grid,area);
                    maxArea=max(area,maxArea);
                }
            }
        }

        return maxArea;
    }
};