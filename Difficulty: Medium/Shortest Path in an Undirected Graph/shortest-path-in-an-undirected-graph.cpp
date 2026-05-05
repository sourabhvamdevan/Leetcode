class Solution {
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
  
        vector<pair<int, int>> adj[n + 1];
        for (auto& it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

   
        vector<int> dist(n + 1, 1e9); 
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; i++) parent[i] = i;

     
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[1] = 0;
        pq.push({0, 1});

        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

          
            if (d > dist[node]) continue;

            for (auto& it : adj[node]) {
                int adjNode = it.first;
                int weight = it.second;

                if (dist[node] + weight < dist[adjNode]) {
                    dist[adjNode] = dist[node] + weight;
                    pq.push({dist[adjNode], adjNode});
                    parent[adjNode] = node;
                }
            }
        }

  
        if (dist[n] == 1e9) return {-1};

        vector<int> path;
        int temp = n;
        while (parent[temp] != temp) {
            path.push_back(temp);
            temp = parent[temp];
        }
        path.push_back(1);
        
    
        path.push_back(dist[n]);
        
    
        reverse(path.begin(), path.end());

        return path;
    }
};