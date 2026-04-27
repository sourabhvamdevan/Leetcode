class Solution {
public:
    void dfs1(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st) {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if(!vis[it]) {
                dfs1(it, adj, vis, st);
            }
            
            
            
    }
        st.push(node); 
    }

    void dfs2(int node, vector<vector<int>> &revAdj, vector<int> &vis) {
        vis[node]=1;
        for(auto it:revAdj[node])
        {
            if (!vis[it]) {
                dfs2(it, revAdj, vis);
            }
            
            
            
        }
    }

    int kosaraju(int V, vector<vector<int>> &edges){
 
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }


        vector<int> vis(V, 0);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs1(i, adj, vis, st);
            }
            
            
            
        }

   
        vector<vector<int>> revAdj(V);
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                revAdj[it].push_back(i);
            }
        }

    
        fill(vis.begin(), vis.end(), 0);
        int scc = 0;

        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (!vis[node]) {
                dfs2(node, revAdj, vis);
                scc++; 
            }
        }

        return scc;
    }
};