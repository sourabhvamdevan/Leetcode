class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited){
        visited[u]=true;
        for (int v:adj[u]){
            if (!visited[v]) {
                dfs(v, adj, visited);
            }
            
            
            
            
        }
    }

    int findMotherVertex(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<bool> visited(V, false);
        int lastFinished = 0;

        for (int i = 0; i < V; i++){
            if (!visited[i]) {
                dfs(i, adj, visited);
                lastFinished = i;
            }
            
            
        }


        fill(visited.begin(), visited.end(), false);
        dfs(lastFinished, adj, visited);

        for (bool v : visited) {
            if (!v) return -1;
        }

        return lastFinished;
    }
};