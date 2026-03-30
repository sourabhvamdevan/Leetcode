class Solution {
public:
    int minCost(vector<vector<int>>& houses) {
        int n = houses.size();
        if (n <= 1) return 0;

        vector<int> min_dist(n, INT_MAX);
        vector<bool> visited(n, false);
        
        int total_cost=0;
        int edges_connected=0;
        
      
        min_dist[0] = 0;

        for (int i = 0; i < n; ++i){
            int u = -1;

    
            for (int v = 0; v < n; ++v) {
                if (!visited[v] && (u == -1 || min_dist[v] < min_dist[u])) {
                    u = v;
                }
            }

     
            visited[u] = true;
            total_cost += min_dist[u];
            edges_connected++;

         
            for (int v = 0; v < n; ++v) {
                if (!visited[v]) {
                    int dist = abs(houses[u][0] - houses[v][0]) + 
                               abs(houses[u][1] - houses[v][1]);
                    
                    if (dist < min_dist[v]) {
                        min_dist[v] = dist;
                    }
                }
            }
        }

        return total_cost;
    }
};