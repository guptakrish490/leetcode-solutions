class Solution {
public:
    bool dfs(int start, int end, vector<int>& vis, vector<vector<int>>& adj) {
        if (start == end) return true;
        vis[start] = 1;

        for (auto it : adj[start]) {
            if (!vis[it]) {
                if (dfs(it, end, vis, adj)) return true;
            }
        }
        return false;
    }


    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);

        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> vis(n,0);
        return dfs(source,destination,vis,adj);
    }
};