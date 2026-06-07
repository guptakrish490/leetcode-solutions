class Solution {
public:
    void dfs(int r,int c,vector<vector<vector<pair<int,int>>>>&adj,vector<vector<int>>& vis){
        vis[r][c]=1;

        for(auto it:adj[r][c]){
            if(!vis[it.first][it.second]){
                dfs(it.first,it.second,adj,vis);
            }
        }
    }


    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<vector<pair<int,int>>>> adj(m, vector<vector<pair<int,int>>>(n));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j>0 && grid[i][j]=='1' && grid[i][j-1]=='1'){
                    adj[i][j].push_back({i,j-1});
                    adj[i][j-1].push_back({i,j});
                }
                if(i>0 && grid[i][j]=='1' && grid[i-1][j]=='1'){
                    adj[i][j].push_back({i-1,j});
                    adj[i-1][j].push_back({i,j});
                }
            }
        }

        vector<vector<int>> vis(m,vector<int>(n,0));

        int cnt=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    cnt++;
                    dfs(i,j,adj,vis);
                }
            }
        }

        return cnt;
    }
};