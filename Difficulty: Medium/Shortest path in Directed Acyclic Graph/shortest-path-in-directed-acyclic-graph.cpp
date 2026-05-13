// User function Template for C++
class Solution {
  public:
  
  void topoSort(int node, vector<int>& vis, stack<int>& st,
              vector<vector<pair<int,int>>>& adj)
              {
    
    vis[node]=1; 


    for (auto &it:adj[node])
    
    
    {
        if (!vis[it.first])
        
        {
            topoSort(it.first, vis, st, adj);
 }
}

    st.push(node);
}
  
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
           vector<vector<pair<int,int>>> adj(V);

    
    for (auto &e:edges)
    
    {
        int u=e[0];
        int v=e[1];
        int wt=e[2];
        adj[u].push_back({v,wt});
    }


    vector<int> vis(V, 0);
    stack<int> st;


    for(int i=0;i<V;i++)
    {
        if(!vis[i]){
            topoSort(i, vis, st, adj);
        }
    }


    const int INF=1e9;
    vector<int> dist(V, INF);
    dist[0] = 0;

    while (!st.empty())
    
    {
        int node = st.top();
        st.pop();

 
        if (dist[node] != INF) {


            for (auto &it : adj[node]) {
                int v = it.first;
                int wt = it.second;

        
                if(dist[node]+wt < dist[v]){
                    dist[v]=dist[node] + wt;
     }
    }
        }
    }

    for(int i=0;i<V;i++){
        if (dist[i]==INF)
        
        {
            dist[i] = -1;
        }
    }
    
    return dist;
    }
};
