class Solution {
  public:
  
  
  
  int find(int i, vector<int>& parent){
      if(parent[i]==i) return i;
      
     return parent[i] =find(parent[i],parent);
     
     
          
      
  }
  
  
    int countConnected(int V, vector<vector<int>>& edges) {
        // code here
        
        vector<int> parent(V);
        
        for(int i=0;i<V;i++){
            parent[i]=i;
            
        }
        
        
        int components=V;
        
        for(auto &edge: edges){
            
            int u=edge[0];
            int v=edge[1];
            
            
            int rootU=find(u,parent);
            int rootV=find(v,parent);
            
            
            if(rootU!=rootV){
                
                parent[rootU]=rootV;
                
                components--;
                
                
            }
        }
        
        
        return components;
        
        
        
    }
};