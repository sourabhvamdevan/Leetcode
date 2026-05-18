

class Solution {
private:
  
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &component_nodes) {
        vis[node] = 1;
        component_nodes.push_back(node);
        
        for (auto adjNode : adj[node]) {
            if (!vis[adjNode]) {
                dfs(adjNode, adj, vis, component_nodes);
            }
        }
    }

public:
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {

        vector<vector<int>> adj(v + 1);
        for (int i = 0; i < e; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> vis(v + 1, 0);
        int goodComponentCount = 0;


        for (int i = 1; i <= v; i++) {
            if (!vis[i]) {
                vector<int> component_nodes;
                
          
                dfs(i, adj, vis, component_nodes);
                
                int num_vertices = component_nodes.size();
                bool is_good = true;

              
                for (int node : component_nodes) {
                    if (adj[node].size() != num_vertices - 1) {
                        is_good = false;
                        break;
                    }
                }

                if (is_good)
                
                {
                    goodComponentCount++;
                }
            }
        }

        return goodComponentCount;
    }
};