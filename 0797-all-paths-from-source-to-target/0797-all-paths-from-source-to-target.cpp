class Solution {
public:
    vector<vector<int>>res;

    void dfs(int start,int end,vector<vector<int>>&adj,vector<int>&paths){
        
        paths.push_back(start);

        if(start==end){
            res.push_back(paths);
        }

        for(auto it:adj[start]){
            dfs(it,end,adj,paths);
        }
        
        paths.pop_back();

    }


    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();

        vector<int>paths;
        dfs(0,n-1,graph,paths);

        return res;
    }
};