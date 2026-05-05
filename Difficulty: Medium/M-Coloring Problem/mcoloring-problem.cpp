class Solution {
  public:

    bool isSafe(int u, vector<int>& color, vector<vector<int>>& adj, int c) {
        for(int neighbor:adj[u]){
            if (color[neighbor] == c) {
                return false;
            }
            
            
            
        }
        return true;
    }


    bool solve(int u, int v, int m, vector<int>& color, vector<vector<int>>& adj) {
   
        if(u==v){
            return true;
            
            
        }

   
        for (int c = 1; c <= m; c++) {
            if (isSafe(u, color, adj, c)) {
                color[u] = c; 

         
                if (solve(u + 1, v, m, color, adj)) {
                    return true;
                }

                color[u] = 0; 
            }
        }

        return false;
    }

    bool graphColoring(int v, vector<vector<int>> &edges, int m) {

        vector<vector<int>> adj(v);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

     
        vector<int> color(v, 0);

  
        return solve(0, v, m, color, adj);
    }
};