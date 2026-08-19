class DisjointSet {
public:
    vector<int> parent;

    DisjointSet(int n) {
        parent.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int i) { // i is index too
        if (parent[i] == i)
            return i;

        return parent[i] = findUPar(parent[i]);
    }

    void unionBySize(int u, int v) { // u & v are indices
        int pu = findUPar(u);
        int pv = findUPar(v);

        parent[pu] = pv;
        
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        // disjoint set banana hai
        // sare stones ke bich union lana hai
        // sabse bada size wala stones ka disjoint set choose karna hai
        // ek ek karke sare stones hat jyenge but ek bach jayega...
        // ds ka maximum size - 1 = answer for this..kyuki max(ds.size) - 1
        // stones htaye jaa skte hai

        int n = stones.size();

        DisjointSet ds(n);
        unordered_map<int, vector<int>> rowMap, colMap;

        for (int i = 0; i < n; i++) {
            rowMap[stones[i][0]].push_back(i);
            colMap[stones[i][1]].push_back(i);
        }

        for (int i = 0; i < n; i++) {
            int x = stones[i][0];
            int y = stones[i][1];

            for (auto& r : rowMap[x]) {
                ds.unionBySize(i, r);
            }
            for (auto& c : colMap[y]) {
                ds.unionBySize(i, c);
            }
        }

        int components = 0;
        for (int i = 0; i < n; i++) {
            if (ds.parent[i] == i)
                components++;
        }

        return n - components;
    }
};