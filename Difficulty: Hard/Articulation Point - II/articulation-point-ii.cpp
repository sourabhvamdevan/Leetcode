class Solution {
private:
    void dfs(int u, int p, int& timer, vector<int> adj[], vector<int>& disc, 
             vector<int>& low, vector<bool>& isArticulation) {
        
        disc[u] = low[u] = ++timer;
        int children = 0;

        for (auto v : adj[u]) {
            if (v == p) continue; 

            if (disc[v]) {
               
                low[u] = min(low[u], disc[v]);
            } else {
               
                children++;
                dfs(v, u, timer, adj, disc, low, isArticulation);
                
              
                low[u] = min(low[u], low[v]);
                
             
                if (p != -1 && low[v] >= disc[u]) {
                    isArticulation[u] = true;
                }
            }
        }
        
     
        if (p == -1 && children > 1) {
            isArticulation[u] = true;
        }
    }

public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> disc(V, 0), low(V, 0);
        vector<bool> isArticulation(V, false);
        int timer = 0;

   
        for (int i = 0; i < V; i++) {
            if (!disc[i]) {
                dfs(i, -1, timer, adj, disc, low, isArticulation);
            }
        }

        vector<int> result;
        for (int i = 0; i < V; i++) {
            if (isArticulation[i]) {
                result.push_back(i);
            }
        }

        if (result.empty()) return {-1};
        return result;
    }
};