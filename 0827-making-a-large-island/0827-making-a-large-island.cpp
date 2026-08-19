class DisjointSet {
public:
    vector<vector<int>> size;
    vector<vector<pair<int, int>>> parent;

    DisjointSet(int n) {
        size.assign(n, vector<int>(n, 1));
        parent.assign(n, vector<pair<int, int>>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                parent[i][j] = {i, j};
            }
        }
    }

    pair<int, int> findUPar(int r, int c) {
        if (parent[r][c] == pair<int, int>{r, c})
            return {r, c};

        auto [pr, pc] = parent[r][c];
        return parent[r][c] = findUPar(pr, pc);
    }

    void unionBySize(int ur, int uc, int vr, int vc) {
        auto ulp_u = findUPar(ur, uc);
        auto ulp_v = findUPar(vr, vc);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u.first][ulp_u.second] < size[ulp_v.first][ulp_v.second]) {
            size[ulp_v.first][ulp_v.second] += size[ulp_u.first][ulp_u.second];
            parent[ulp_u.first][ulp_u.second] = ulp_v;
        } else {
            size[ulp_u.first][ulp_u.second] += size[ulp_v.first][ulp_v.second];
            parent[ulp_v.first][ulp_v.second] = ulp_u;
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        // pehle saree 1's ka disjoint set using size banana hai
        // grid pe iterate karna hai for every 0's
        // har 0's ko 1's se replace karke fir uske 4-directionally union apply
        // karna hai agar union apply hota hai toh jitne bhi islands ka union
        // bana unka size ka sum lena hai result mai maximum wala size return
        // karna hai

        struct pair_hash {
            size_t operator()(const pair<int, int>& p) const {
                return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
            }
        };

        int largestIslandSize = 0;
        int n = grid.size();

        DisjointSet ds(n);

        int zeroCnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (!grid[i][j]) {
                    zeroCnt++;
                    continue;
                }

                int dr[4] = {-1, 1, 0, 0};
                int dc[4] = {0, 0, 1, -1};

                for (int k = 0; k < 4; k++) {
                    int nr = i + dr[k];
                    int nc = j + dc[k];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                        grid[nr][nc]) {
                        ds.unionBySize(i, j, nr, nc);
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    auto [pr, pc] = ds.findUPar(i, j);
                    largestIslandSize = max(largestIslandSize, ds.size[pr][pc]);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<pair<int, int>, pair_hash> parents;
                    int dr[4] = {-1, 1, 0, 0};
                    int dc[4] = {0, 0, 1, -1};

                    for (int k = 0; k < 4; k++) {
                        int nr = i + dr[k];
                        int nc = j + dc[k];

                        if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                            grid[nr][nc]) {
                            auto [pr, pc] = ds.parent[nr][nc];

                            parents.insert(ds.findUPar(pr, pc));
                        }
                    }

                    int islandSize = 1;
                    for (auto it : parents) {
                        islandSize += ds.size[it.first][it.second];
                    }

                    largestIslandSize = max(islandSize, largestIslandSize);
                }
            }
        }
        cout << zeroCnt;

        return largestIslandSize;
    }
};