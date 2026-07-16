class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<>>
            pq;
        vector<vector<int>> dist(n, (vector<int>(k + 2, 1e9)));

        dist[src][0] = 0;
        pq.push({0, src, 0});

        while (!pq.empty()) {
            auto [cost, node, stop] = pq.top();
            pq.pop();

            if (node == dst)
                return cost;
            if (stop > k)
                continue;

            for (auto it : adj[node]) {
                auto [next, price] = it;

                if (cost + price < dist[next][stop + 1]) {
                    dist[next][stop + 1] = cost + price;
                    pq.push({dist[next][stop + 1], next, stop + 1});
                }
            }
        }

        return -1;
    }
};