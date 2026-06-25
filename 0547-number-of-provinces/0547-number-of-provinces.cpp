class Solution {
public:
    void traverse(int i, vector<int>adj[], vector<int>& vis){
        
        vis[i]=1;

        for(auto it:adj[i]){
            if(!vis[it]){
                traverse(it,adj,vis);
            }
        }
    }


    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        
        vector<int> adj[n];

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                }
            }
        }

        vector<int>vis(n,0);

        int cnt=0;

        for(int j=0;j<n;j++){
            if(!vis[j]){
                cnt++;
                traverse(j,adj,vis);
            }
        }

        return cnt;
    }
};