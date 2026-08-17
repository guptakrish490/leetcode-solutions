class DisjointSet {
public:
    unordered_map<string, string> parent;
    unordered_map<string, int> size;
    unordered_map<string, string> accountHolder;

    DisjointSet(vector<vector<string>>& accounts) {
        int n = accounts.size();

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                parent[accounts[i][j]] = accounts[i][j];
                size[accounts[i][j]] = 1;
                accountHolder[accounts[i][j]] = accounts[i][0];
            }
        }
    }

    string findUPar(string node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(string u, string v) {
        string ulp_u = findUPar(u);
        string ulp_v = findUPar(v);

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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // doo accounts ko merge karna hai 
        // agar dono ke emails mai se ek bhi match kar jaye toh merge karne k bad accounts ka array return karna hai
        // array mai emails sorted order mai hone chaiye but accounts unsorted ho skte hai

        // har ek account mai se uske emails ko union banana hai
        // hashmap parent k sath uske child strore karega using set
        // set sab khud sort karke store karrega
        // hashmap store hone k bad uspe iterate krke pehle ultimate parent or accountHolder ki help se name store karna hai fir saree emails
        // resultant array apne ap sorted emails store krega bcoz of sets

        DisjointSet ds(accounts);

        vector<vector<string>> ans;
        unordered_map<string, set<string>> account;

        for (auto& acc : accounts) {
            string firstMail = acc[1];
            for (int j = 2; j < acc.size(); j++) {
                ds.unionBySize(firstMail, acc[j]);
            }
        }

        for (int i = 0; i < accounts.size(); i++) {

            for (int j = 1; j < accounts[i].size(); j++) {
                string parNode = ds.findUPar(accounts[i][j]);
                account[parNode].insert(accounts[i][j]);
            }
        }

        for (auto it : account) {
            vector<string> merged;
            merged.push_back(ds.accountHolder[it.first]);

            for (auto& email : it.second) {
                merged.push_back(email);
            }

            ans.push_back(merged);
        }

        return ans;
    }
};