

class Solution {
public:
    bool checkCycle(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& pathVisited, vector<int>& safe) {
        visited[node] = 1;
        pathVisited[node] = 1;
        safe[node] = 0;

        for (auto it : adj[node]) {
     
            if (!visited[it]) {
                if (checkCycle(it, adj, visited, pathVisited, safe)) {
                    return true;
                }
            }
      
            else if (pathVisited[it]) {
                return true;
            }
        }

        safe[node] = 1;
        pathVisited[node] = 0;
        return false;
    }

    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
   
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<int> visited(V, 0);
        vector<int> pathVisited(V, 0);
        vector<int> safe(V, 0);
        vector<int> ans;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                checkCycle(i, adj, visited, pathVisited, safe);
            }
        }

        for (int i = 0; i < V; i++) {
            if (safe[i] == 1) ans.push_back(i);
        }

        return ans;
    }
};