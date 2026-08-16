class DisjointSet {
public:
    vector<int> size, parent;

    DisjointSet(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v]) {
            size[ulp_v] += size[ulp_u];
            parent[ulp_u] = ulp_v;
        } else {
            size[ulp_u] += size[ulp_v];
            parent[ulp_v] = ulp_u;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;

        // pehle MST build kar
        // no. of edges - no.of edges in MST = answer
        // extra wires jo hai usse hta skte or dusre jagh place kar sakte hai

        int groups = 0;

        DisjointSet ds(n);

        for (auto it : connections) {
            ds.unionBySize(it[0], it[1]);
        }

        for (int i = 0; i < n; i++) {
            if (ds.findUPar(i) == i) {
                groups++;
            }
        }

        return groups - 1;
    }
};