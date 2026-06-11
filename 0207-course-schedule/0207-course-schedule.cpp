class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;

        for (auto it : adj[node]) {
            if (vis[it]==1) {
                return false;
            } else if (!vis[it]) {
                if (!dfs(it, adj, vis))
                    return false;
            }
        }
        vis[node]=2;

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for (int i = 0; i < adj.size(); i++) {
            if (!vis[i]) {
                if (!dfs(i, adj, vis))
                    return false;
            }
        }

        return true;
    }
};