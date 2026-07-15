class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        set<pair<int, int>> st;
        vector<vector<pair<int, int>>> adj(n+1);

        for (int i = 0; i < times.size(); i++) {
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        int minTime = 0;
        vector<int> dist(n+1, 1e9);

        dist[k] = 0;
        st.insert({0, k});

        while (!st.empty()) {
            auto [dis, node] = *(st.begin());
            st.erase(st.begin());

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edgeWeight = it.second;

                if (dis + edgeWeight < dist[adjNode]) {
                    if (dist[adjNode] != 1e9) {
                        st.erase({dist[adjNode], adjNode});
                    }
                    dist[adjNode] = dis + edgeWeight;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }

        for (int i=1;i<dist.size();i++) {
            if (dist[i] == 1e9) return -1;
            minTime = max(minTime, dist[i]);
        }

        return minTime;
    }
};