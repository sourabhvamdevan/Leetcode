#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int countPaths(int V, vector<vector<int>>& edges) {
        long long MOD = 1e9 + 7;
        
        vector<pair<int, int>> adj[V];
        for (auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

     
        vector<long long> dist(V, 1e18); 
        vector<long long> ways(V, 0);

      
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            long long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

      
            if (d > dist[u]) continue;

            for (auto& edge : adj[u]) {
                int v = edge.first;
                long long time = edge.second;

              
                if (dist[u] + time < dist[v]) {
                    dist[v] = dist[u] + time;
                    ways[v] = ways[u]; 
                    pq.push({dist[v], v});
                }
              
                else if (dist[u] + time == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return ways[V - 1] % MOD;
    }
};