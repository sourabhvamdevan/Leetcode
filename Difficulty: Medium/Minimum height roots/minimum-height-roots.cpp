#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
 
        if (V == 1) return {0};
        

        vector<vector<int>> adj(V);
      
        vector<int> degree(V, 0);
        

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        

        queue<int> leaves;
        for (int i = 0; i < V; ++i) {
            if (degree[i] == 1) {
                leaves.push(i);
            }
        }
        
  
        int remainingNodes = V;
        while (remainingNodes > 2) {
            int currentLeafCount = leaves.size();
            remainingNodes -= currentLeafCount;
            
            for (int i = 0; i < currentLeafCount; ++i) {
                int leaf = leaves.front();
                leaves.pop();
                
    
                for (int neighbor : adj[leaf]) {
              
                    degree[neighbor]--;
            
                    if (degree[neighbor] == 1) {
                        leaves.push(neighbor);
                    }
                }
            }
        }
        

        vector<int> result;
        while (!leaves.empty()) {
            result.push_back(leaves.front());
            leaves.pop();
        }
        
        return result;
    }
};