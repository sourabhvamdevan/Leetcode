class Solution {
  public:
    int longestCycle(int V, vector<vector<int>>& edges) {
        vector<int> adj(V, -1);
        for (auto& edge : edges) {
            adj[edge[0]] = edge[1];
        }

        vector<int> vis(V, 0);
        int maxCycle = -1;

        for (int i = 0; i < V; i++) {
            if (vis[i]) continue;

            int curr = i;
            int distance = 0;
            unordered_map<int, int> nodeDist;
            vector<int> path;

            while (curr != -1 && !vis[curr]) {
                vis[curr] = 1;
                nodeDist[curr] = distance++;
                path.push_back(curr);
                curr = adj[curr];
            }

            if (curr != -1 && nodeDist.count(curr)) {
                maxCycle = max(maxCycle, distance - nodeDist[curr]);
            }
        }

        return maxCycle;
    }
};