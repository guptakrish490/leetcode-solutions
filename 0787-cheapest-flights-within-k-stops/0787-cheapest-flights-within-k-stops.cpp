class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }


        vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX));
        dist[src][0] = 0;

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({0, src, 0});

        while (!pq.empty()) {
            auto [cost, node, stops] = pq.top();
            pq.pop();

            if (node == dst) return cost;
            if (stops == k+1) continue;

            for (auto &edge : adj[node]) {
                int next = edge.first;
                int price = edge.second;

                if (cost + price < dist[next][stops+1]) {
                    dist[next][stops+1] = cost + price;
                    pq.push({dist[next][stops+1], next, stops+1});
                }
            }
        }

        return -1;
    }
};
