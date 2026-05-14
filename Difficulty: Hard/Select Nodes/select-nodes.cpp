// User function Template for C++

class Solution {
  public:
 
    vector<vector<int>> dp;
    vector<vector<int>> adj;

    void dfs(int u, int p) {
        dp[u][0] = 0;
        dp[u][1] = 1;

        for (int v : adj[u]) {
            if (v == p) continue;
            
            dfs(v, u);

     
            dp[u][0] += dp[v][1];
            
        
            dp[u][1] += min(dp[v][0], dp[v][1]);
        }
    }

    int countVertex(int N, vector<vector<int>> edges) {
        adj.assign(N + 1, vector<int>());
        dp.assign(N + 1, vector<int>(2, 0));

  
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

   
        dfs(1, -1);

    
        return min(dp[1][0], dp[1][1]);
    }
};