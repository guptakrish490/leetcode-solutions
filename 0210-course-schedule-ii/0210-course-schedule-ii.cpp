class Solution {
public:
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V=numCourses;
        vector<int>topo;
        vector<vector<int>>adj(V);
        vector<int> indegree(V,0);
        queue<int>q;

        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int node=q.front(); q.pop();
            topo.push_back(node);

            for(auto it:adj[node]){
                indegree[it]--;
                if(!indegree[it]) q.push(it);
            }
        }


        if(topo.size()==V) return topo;
        return {};

    }
};