class Solution {
public:
    bool dfs(int start, vector<vector<int>>& graph, vector<int>& vis,
             int color) {
        vis[start] = color;

        for (auto it : graph[start]) {
            if (vis[it] == -1) {
                if (!dfs(it, graph, vis, !color)) return false;
            } else if (vis[it] == color)
                return false;
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(), -1);

        for(int i=0;i<graph.size();i++){
            if(vis[i]==-1){
                if(!dfs(i,graph,vis,1)) return false;
            }
        }

        return true;
        
    }
};