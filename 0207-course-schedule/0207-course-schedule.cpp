class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V=numCourses;
        int cnt=0;
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
            cnt++;

            for(auto it:adj[node]){
                indegree[it]--;
                if(!indegree[it]) q.push(it);
            }
        }


        return cnt==V;
    }
};