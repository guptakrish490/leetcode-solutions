class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        // har node se dusre tak ka shortest find kar
        // agar shortest path < threshold, then neighbourCount[node]++;
        // answer variable, that stores the node with min neighbourCount till
        // now agar node with min neighbourCount are same for more than one
        // node, take the bigger node.

        // intution-> find shortest path from a node to all other nodes for each
        // vertex

        vector<vector<pair<int, int>>> adj(n);
        int ans;

        for (int i = 0; i < edges.size(); i++) {
            int from = edges[i][0];
            int to = edges[i][1];
            int edgeWeight = edges[i][2];

            adj[from].push_back({to, edgeWeight});
            adj[to].push_back({from, edgeWeight});
        }

        vector<int> neighbourCount(n, 0);
        int minNeighbourCount = 1e9;

        vector<vector<long long>> dist(n, vector<long long>(n, 1e12));

        for (int i = 0; i < n; i++) {
            // find shortest path from i to all other node using dijkstra algo
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

            dist[i][i] = 0;
            pq.push({0, i});

            while (!pq.empty()) {
                auto [distance, node] = pq.top();
                pq.pop();

                for (auto it : adj[node]) {
                    auto [adjNode, edgeWt] = it;

                    if (distance + edgeWt < dist[i][adjNode]) {
                        dist[i][adjNode] = distance + edgeWt;
                        pq.push({dist[i][adjNode], adjNode});
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                if (dist[i][j] <= distanceThreshold) {
                    neighbourCount[i]++;
                }
            }

            if (minNeighbourCount >= neighbourCount[i]) {
                minNeighbourCount = neighbourCount[i];
                ans = i;
            }
        }

        return ans;
    }
};